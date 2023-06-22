/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/just.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"hello"};
        constexpr std::size_t length = 10;
        constexpr auto fillchar = '*';
        const auto& result = strpy::ljust(str, length, fillchar);

        std::cout << "String: " << str << '\n';
        std::cout << "Length: " << length << '\n';
        std::cout << "Fill character: " << fillchar << '\n';
        std::cout << "Left-justified string: " << result << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"hello"};
        constexpr std::size_t length = 10;
        constexpr auto fillchar = '*';
        const auto& result = strpy::rjust(str, length, fillchar);

        std::cout << "String: " << str << '\n';
        std::cout << "Length: " << length << '\n';
        std::cout << "Fill character: " << fillchar << '\n';
        std::cout << "Right-justified string: " << result << '\n';
    }

    void example3()
    {
        constexpr std::string_view str{"42"};
        constexpr std::size_t length = 6;
        const auto& result = strpy::zfill(str, length);

        std::cout << "String: " << str << '\n';
        std::cout << "Length: " << length << '\n';
        std::cout << "Zero-filled string: " << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (ljust)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (rjust)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (zfill)" << '\n';
    example3();

    return 0;
}

// Program output:
//
// Example 1 (ljust)
// String: hello
// Length: 10
// Fill character: *
// Left-justified string: hello*****
//
// Example 2 (rjust)
// String: hello
// Length: 10
// Fill character: *
// Right-justified string: *****hello
//
// Example 3 (zfill)
// String: 42
// Length: 6
// Zero-filled string: 000042
