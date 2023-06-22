/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/format.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr auto age = 25;
        constexpr std::string_view name{"John"};
        const auto& result = strpy::format("My name is {}, and I am {} years old.", name, age);

        std::cout << "Name: " << name << '\n';
        std::cout << "Age: " << age << '\n';
        std::cout << "Formatted string: " << result << '\n';
    }

    void example2()
    {
        constexpr auto age = 25;
        const auto& result = strpy::to_string(age);

        std::cout << "Age: " << age << '\n';
        std::cout << "Age in string format: \"" << result << "\"" << '\n';
    }

    void example3()
    {
        constexpr auto price = 9.99;
        const auto& result = strpy::to_string(price, std::ios_base::fixed | std::ios_base::showpoint);

        std::cout << "Price: $" << price << '\n';
        std::cout << "Price in string format: \"$" << result << "\"" << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (format)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (to_string)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (to_string with formatting flags)" << '\n';
    example3();
    std::cout << '\n';

    return 0;
}

// Program output:
//
// Example 1 (format)
// Name: John
// Age: 25
// Formatted string: My name is John, and I am 25 years old.
//
// Example 2 (to_string)
// Age: 25
// Age in string format: "25"
//
// Example 3 (to_string with formatting flags)
// Price: $9.99
// Price in string format: "$9.990000"
