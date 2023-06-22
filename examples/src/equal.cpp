/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/equal.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"hello world"};
        constexpr std::size_t start = 6;
        constexpr std::size_t end = 11;
        const auto result = strpy::equal(str, "world", start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring (start " << start << " end " << end << "): " << str.substr(start, end - start) << '\n';
        std::cout << "Does the substring 'world' match 'world'? " << std::boolalpha << result << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"HeLLo WoRLD"};
        const auto result = strpy::equal_icase(str, "Hello World");

        std::cout << "String: " << str << '\n';
        std::cout << "Does the string 'HeLLo WoRLD' match 'Hello World'? " << std::boolalpha << result << '\n';
    }

    void example3()
    {
        constexpr auto ch1 = 'a';
        constexpr auto ch2 = L'A';
        const auto result = strpy::equal_char_icase(ch1, ch2);

        std::cout << "Character 1: " << ch1 << '\n';
        std::cout << "Character 2: " << ch2 << '\n';
        std::cout << "Are the characters equal? " << std::boolalpha << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (equal)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (equal_icase)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (equal_char_icase)" << '\n';
    example3();

    return 0;
}

// Program output:
//
// Example 1 (equal)
// String: hello world
// Substring (start 6 end 11): world
// Does the substring 'world' match 'world'? true
//
// Example 2 (equal_icase)
// String: HeLLo WoRLD
// Does the string 'HeLLo WoRLD' match 'Hello World'? true
//
// Example 3 (equal_char_icase)
// Character 1: a
// Character 2: 65
// Are the characters equal? true
