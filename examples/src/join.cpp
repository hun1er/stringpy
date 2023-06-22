/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/join.hpp"
#include <array>
#include <iostream>
#include <list>
#include <vector>

namespace
{
    void example1()
    {
        const std::vector<std::string> words = {"Hello", "World"};
        const auto& result = strpy::join(words, " ");

        std::cout << "Words:" << '\n' << strpy::join(words, "\n") << '\n';
        std::cout << "Delimiter: \" \"" << '\n';
        std::cout << "Joined: " << result << '\n';
    }

    void example2()
    {
        const std::list numbers = {1, 2, 3};
        const auto& result = strpy::join(numbers, ", ");

        std::cout << "Numbers:" << '\n' << strpy::join(numbers, "\n") << '\n';
        std::cout << "Delimiter: \", \"" << '\n';
        std::cout << "Joined: " << result << '\n';
    }

    void example3()
    {
        constexpr std::array<char, 3> characters = {'a', 'b', 'c'};
        const auto& result = strpy::join(characters, "-");

        std::cout << "Characters:" << '\n' << strpy::join(characters, "\n") << '\n';
        std::cout << "Delimiter: \"-\"" << '\n';
        std::cout << "Joined: " << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (words)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (numbers)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (characters)" << '\n';
    example3();

    return 0;
}

// Program output:
//
// Example 1 (words)
// Words:
// Hello
// World
// Delimiter: " "
// Joined: Hello World
//
// Example 2 (numbers)
// Numbers:
// 1
// 2
// 3
// Delimiter: ", "
// Joined: 1, 2, 3
//
// Example 3 (characters)
// Characters:
// a
// b
// c
// Delimiter: "-"
// Joined: a-b-c
