/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/startswith.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"Hello, world!"};
        constexpr std::string_view prefix{"Hello"};
        const auto result = strpy::starts_with(str, prefix);

        std::cout << "String: " << str << '\n';
        std::cout << "Does the string start with the prefix '" << prefix << "'? " << std::boolalpha << result << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"This is an example string."};
        constexpr std::size_t start = 5;
        constexpr std::size_t end = 10;
        const auto result = strpy::starts_with(str, "is", start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring (start " << start << " end " << end << "): " << str.substr(start, end - start) << '\n';
        std::cout << "Does the substring 'is an' start with the prefix 'is'? " << std::boolalpha << result << '\n';
    }

    void example3()
    {
        constexpr std::string_view str{"hELLo, WoRLd!"};
        constexpr std::string_view prefix{"hello"};
        const auto result = strpy::starts_with_icase(str, prefix);

        std::cout << "String: " << str << '\n';
        std::cout << "Does the string start with the prefix '" << prefix << "'? " << std::boolalpha << result << '\n';
    }

    void example4()
    {
        constexpr std::string_view str{"This is an EXAMPLE string."};
        constexpr std::size_t start = 11;
        const auto result = strpy::starts_with_icase(str, "example", start);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring (start " << start << "): " << str.substr(start) << '\n';
        std::cout << "Does the substring 'EXAMPLE string.' start with 'example'? " << std::boolalpha << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (starts_with)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (starts_with)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (starts_with_icase)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (starts_with_icase)" << '\n';
    example4();

    return 0;
}

// Program output:
//
// Example 1 (starts_with)
// String: Hello, world!
// Does the string start with the prefix 'Hello'? true
//
// Example 2 (starts_with)
// String: This is an example string.
// Substring (start 5 end 10): is an
// Does the substring 'is an' start with the prefix 'is'? true
//
// Example 3 (starts_with_icase)
// String: hELLo, WoRLd!
// Does the string start with the prefix 'hello'? true
//
// Example 4 (starts_with_icase)
// String: This is an EXAMPLE string.
// Substring (start 11): EXAMPLE string.
// Does the substring 'EXAMPLE string.' start with 'example'? true
