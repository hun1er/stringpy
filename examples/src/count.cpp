/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/count.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"hello world, hello again"};
        constexpr std::string_view sub{"hello"};
        const auto result = strpy::count(str, sub);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring: " << sub << '\n';
        std::cout << "Count: " << result << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"HeLLo WoRLD, HeLLo aGaiN"};
        constexpr std::string_view sub{"hello"};
        constexpr std::size_t start = 13;
        constexpr std::size_t end = 18;
        const auto result = strpy::count_icase(str, sub, start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring: " << sub << '\n';
        std::cout << "Start: " << start << '\n';
        std::cout << "End: " << end << '\n';
        std::cout << "Count: " << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (count)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (count_icase)" << '\n';
    example2();

    return 0;
}

// Program output:
//
// Example 1 (count)
// String: hello world, hello again
// Substring: hello
// Count: 2
//
// Example 2 (count_icase)
// String: HeLLo WoRLD, HeLLo aGaiN
// Substring: hello
// Start: 13
// End: 18
// Count: 1
