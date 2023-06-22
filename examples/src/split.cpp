/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/split.hpp"
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
        constexpr std::string_view str{"apple\t\r\nbanana cherry"};
        constexpr std::size_t maxsplit = 1;
        const auto& result = strpy::split(str, maxsplit);

        std::cout << "String: ";
        print_string_with_control_chars(str);
        std::cout << '\n';

        std::cout << "Max split: " << maxsplit << '\n';
        std::cout << "Result: ";
        print_container(result);
        std::cout << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"apple,banana,cherry"};
        constexpr std::string_view delimiter{","};
        const auto& result = strpy::split(str, delimiter);

        std::cout << "String: \"" << str << "\"" << '\n';
        std::cout << "Delimiter: \"" << delimiter << "\"" << '\n';
        std::cout << "Result: ";
        print_container(result);
        std::cout << '\n';
    }

    void example3()
    {
        constexpr std::string_view str{"apple\t\r\nbanana cherry"};
        constexpr std::size_t maxsplit = 1;
        const auto& result = strpy::rsplit(str, maxsplit);

        std::cout << "String: ";
        print_string_with_control_chars(str);
        std::cout << '\n';

        std::cout << "Max split: " << maxsplit << '\n';
        std::cout << "Result: ";
        print_container(result);
        std::cout << '\n';
    }

    void example4()
    {
        constexpr std::string_view str{"apple,banana,cherry"};
        constexpr std::string_view delimiter{","};
        constexpr std::size_t maxsplit = 1;
        const auto& result = strpy::rsplit(str, delimiter, maxsplit);

        std::cout << "String: \"" << str << "\"" << '\n';
        std::cout << "Delimiter: \"" << delimiter << "\"" << '\n';
        std::cout << "Max split: " << maxsplit << '\n';
        std::cout << "Result: ";
        print_container(result);
        std::cout << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (split)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (split with delimiter)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (rsplit)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (rsplit with delimiter)" << '\n';
    example4();

    return 0;
}

// Program output:
//
// Example 1 (split)
// String: apple\t\r\nbanana cherry
// Max split: 1
// Result: ["apple", "\r\nbanana cherry"]
//
// Example 2 (split with delimiter)
// String: "apple,banana,cherry"
// Delimiter: ","
// Result: ["apple", "banana", "cherry"]
//
// Example 3 (rsplit)
// String: apple\t\r\nbanana cherry
// Max split: 1
// Result: ["apple\t\r\nbanana", "cherry"]
//
// Example 4 (rsplit with delimiter)
// String: "apple,banana,cherry"
// Delimiter: ","
// Max split: 1
// Result: ["apple,banana", "cherry"]
