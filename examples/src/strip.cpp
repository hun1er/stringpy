/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/strip.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"   Hello, world!   "};
        const auto& result = strpy::lstrip(str);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Stripped string: '" << result << "'\n";
    }

    void example2()
    {
        constexpr std::string_view str{"HHHhello, world!"};
        constexpr auto ch = 'H';
        const auto& result = strpy::lstrip(str, ch);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Character to remove: '" << ch << "'\n";
        std::cout << "Stripped string: '" << result << "'\n";
    }

    void example3()
    {
        constexpr std::string_view str{"Hello, world!   "};
        const auto& result = strpy::rstrip(str);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Stripped string: '" << result << "'\n";
    }

    void example4()
    {
        constexpr std::string_view str{"Hello, world!!!"};
        constexpr auto ch = '!';
        const auto& result = strpy::rstrip(str, ch);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Character to remove: '" << ch << "'\n";
        std::cout << "Stripped string: '" << result << "'\n";
    }

    void example5()
    {
        constexpr std::string_view str{"   Hello, world!   "};
        const auto& result = strpy::strip(str);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Stripped string: '" << result << "'\n";
    }

    void example6()
    {
        constexpr std::string_view str{"!!!Hello, world!!!"};
        constexpr auto ch = '!';
        const auto& result = strpy::strip<std::string_view>(str, ch);

        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Character to remove: '" << ch << "'\n";
        std::cout << "Stripped string: '" << result << "'\n";
    }
}

int main()
{
    std::cout << "Example 1 (lstrip)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (lstrip with character)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (rstrip)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (rstrip with character)" << '\n';
    example4();
    std::cout << '\n';

    std::cout << "Example 5 (strip)" << '\n';
    example5();
    std::cout << '\n';

    std::cout << "Example 6 (strip with character)" << '\n';
    example6();

    return 0;
}

// Program output:
//
// Example 1 (lstrip)
// Original string: '   Hello, world!   '
// Stripped string: 'Hello, world!   '
//
// Example 2 (lstrip with character)
// Original string: 'HHHhello, world!'
// Character to remove: 'H'
// Stripped string: 'hello, world!'
//
// Example 3 (rstrip)
// Original string: 'Hello, world!   '
// Stripped string: 'Hello, world!'
//
// Example 4 (rstrip with character)
// Original string: 'Hello, world!!!'
// Character to remove: '!'
// Stripped string: 'Hello, world'
//
// Example 5 (strip)
// Original string: '   Hello, world!   '
// Stripped string: 'Hello, world!'
//
// Example 6 (strip with character)
// Original string: '!!!Hello, world!!!'
// Character to remove: '!'
// Stripped string: 'Hello, world'
