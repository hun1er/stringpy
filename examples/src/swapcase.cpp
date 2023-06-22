/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/swapcase.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr auto ch = 'a';
        const auto result = strpy::swap_case_char(ch);

        std::cout << "Original character: '" << ch << "'\n";
        std::cout << "Character with case swapped: '" << result << "'\n";
    }

    void example2()
    {
        constexpr auto ch = 'A';
        const auto result = strpy::swap_case_char(ch);

        std::cout << "Original character: '" << ch << "'\n";
        std::cout << "Character with case swapped: '" << result << "'\n";
    }

    void example3()
    {
        constexpr std::string_view str{"Hello, World!"};
        const auto& result = strpy::swap_case(str);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "String with case of all characters swapped: '" << result << "'\n";
    }
}

int main()
{
    std::cout << "Example 1 (swap_case_char lowercase)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (swap_case_char uppercase)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (swap_case)" << '\n';
    example3();

    return 0;
}

// Program output:
//
// Example 1 (swap_case_char lowercase)
// Original character: 'a'
// Character with case swapped: 'A'
//
// Example 2 (swap_case_char uppercase)
// Original character: 'A'
// Character with case swapped: 'a'
//
// Example 3 (swap_case)
// Original string: 'Hello, World!'
// String with case of all characters swapped: 'hELLO, wORLD!'
