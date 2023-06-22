/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/splitlines.hpp"
#include <cstddef>
#include <iostream>

namespace
{
    void print_string_with_control_chars(const std::string_view str)
    {
        for (const auto ch : str) {
            switch (ch) {
                case '\t': std::cout << "\\t"; break;
                case '\n': std::cout << "\\n"; break;
                case '\r': std::cout << "\\r"; break;
                default: std::cout << ch; break;
            }
        }
    }

    template <typename Container>
    void print_container(const Container& container)
    {
        std::cout << "[";
        const auto size = container.size();

        for (std::size_t i = 0; i < size; ++i) {
            std::cout << '"';
            print_string_with_control_chars(container[i]);
            std::cout << '"';

            if (i != (size - 1)) {
                std::cout << ", ";
            }
        }

        std::cout << "]";
    }
}

namespace
{
    void example1()
    {
        constexpr std::string_view str{"apple banana\ncherry grape\r\norange lemon"};
        constexpr bool keep_ends = true;
        const auto& result = strpy::split_lines(str, keep_ends);

        std::cout << "String: ";
        print_string_with_control_chars(str);
        std::cout << '\n';

        std::cout << "Keep ends: " << std::boolalpha << keep_ends << '\n';
        std::cout << "Result: ";
        print_container(result);
        std::cout << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"apple banana\ncherry grape\r\norange lemon"};
        constexpr bool keep_ends = false;
        const auto& result = strpy::split_lines(str, keep_ends);

        std::cout << "String: ";
        print_string_with_control_chars(str);
        std::cout << '\n';

        std::cout << "Keep ends: " << std::boolalpha << keep_ends << '\n';
        std::cout << "Result: ";
        print_container(result);
        std::cout << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (split_lines keep ends)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (split_lines don't keep ends)" << '\n';
    example2();

    return 0;
}

// Program output:
//
// Example 1 (split_lines keep ends)
// String: apple banana\ncherry grape\r\norange lemon
// Keep ends: true
// Result: ["apple banana\n", "cherry grape\r\n", "orange lemon"]
//
// Example 2 (split_lines don't keep ends)
// String: apple banana\ncherry grape\r\norange lemon
// Keep ends: false
// Result: ["apple banana", "cherry grape", "orange lemon"]
