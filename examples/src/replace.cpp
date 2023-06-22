/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/replace.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"I have 10 apples and 20 oranges."};
        constexpr std::string_view old_value{"10"};
        constexpr std::string_view new_value{"20"};
        const auto& result = strpy::replace(str, old_value, new_value);

        std::cout << "String: " << str << '\n';
        std::cout << "Old value: " << old_value << '\n';
        std::cout << "New value: " << new_value << '\n';
        std::cout << "Replaced: " << result << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"I have a cat. My cat is black."};
        constexpr std::string_view old_value{"CaT"};
        constexpr std::string_view new_value{"dog"};
        constexpr std::size_t count = 1;
        const auto& result = strpy::replace_icase(str, old_value, new_value, count);

        std::cout << "String: " << str << '\n';
        std::cout << "Old value: " << old_value << '\n';
        std::cout << "New value: " << new_value << '\n';
        std::cout << "Count: " << count << '\n';
        std::cout << "Replaced: " << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (replace)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (replace_icase)" << '\n';
    example2();

    return 0;
}

// Program output:
//
// Example 1 (replace)
// String: I have 10 apples and 20 oranges.
// Old value: 10
// New value: 20
// Replaced: I have 20 apples and 20 oranges.
//
// Example 2 (replace_icase)
// String: I have a cat. My cat is black.
// Old value: CaT
// New value: dog
// Count: 1
// Replaced: I have a dog. My cat is black.
