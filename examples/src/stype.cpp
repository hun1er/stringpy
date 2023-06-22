/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/stype.hpp"
#include <iostream>

namespace
{
    void print_string_with_control_chars(const std::string_view str)
    {
        std::cout << "String: '";

        for (const auto ch : str) {
            switch (ch) {
                case '\t': std::cout << "\\t"; break;
                case '\n': std::cout << "\\n"; break;
                case '\r': std::cout << "\\r"; break;
                default: std::cout << ch; break;
            }
        }

        std::cout << "'\n";
    }
}

namespace
{
    void example1()
    {
        constexpr std::string_view str{"hello_world"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Is the string a valid identifier? " << std::boolalpha << strpy::is_identifier(str) << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"Hello, World!"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Is the string a titlecased string? " << std::boolalpha << strpy::is_title(str) << '\n';
    }

    void example3()
    {
        constexpr std::string_view str{"hello123"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string alphanumeric? " << std::boolalpha << strpy::is_alnum(str)
                  << '\n';
    }

    void example4()
    {
        constexpr std::string_view str{"hello"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string alphabetic? " << std::boolalpha << strpy::is_alpha(str) << '\n';
    }

    void example5()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string ASCII characters? " << std::boolalpha << strpy::is_ascii(str)
                  << '\n';
    }

    void example6()
    {
        constexpr std::string_view str{" \t"};
        print_string_with_control_chars(str);
        std::cout << "Are all characters in the string blank? " << std::boolalpha << strpy::is_blank(str) << '\n';
    }

    void example7()
    {
        constexpr std::string_view str{"\n"};
        print_string_with_control_chars(str);
        std::cout << "Are all characters in the string control characters? " << std::boolalpha << strpy::is_cntrl(str)
                  << '\n';
    }

    void example8()
    {
        constexpr std::string_view str{"123"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string decimal digits? " << std::boolalpha << strpy::is_digit(str)
                  << '\n';
    }

    void example9()
    {
        constexpr std::string_view str{" \t\n"};
        print_string_with_control_chars(str);
        std::cout << "Is the string empty or contains only whitespace characters? " << std::boolalpha
                  << strpy::is_empty_or_space(str) << '\n';
    }

    void example10()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string graphical characters? " << std::boolalpha << strpy::is_graph(str)
                  << '\n';
    }

    void example11()
    {
        constexpr std::string_view str{"hello"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string lowercase? " << std::boolalpha << strpy::is_lower(str) << '\n';
    }

    void example12()
    {
        constexpr const char* str = nullptr;
        std::cout << "String: nullptr\n";
        std::cout << "Is the string null or empty? " << std::boolalpha << strpy::is_null_or_empty(str) << '\n';
    }

    void example13()
    {
        constexpr const char* str = nullptr;
        std::cout << "String: nullptr\n";
        std::cout << "Is the string null, empty or contains only whitespace characters? " << std::boolalpha
                  << strpy::is_null_or_space(str) << '\n';
    }

    void example14()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string printable characters? " << std::boolalpha
                  << strpy::is_printable(str) << '\n';
    }

    void example15()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string punctuation characters? " << std::boolalpha
                  << strpy::is_punct(str) << '\n';
    }

    void example16()
    {
        constexpr std::string_view str{" \t\n"};
        print_string_with_control_chars(str);
        std::cout << "Are all characters in the string whitespace characters? " << std::boolalpha
                  << strpy::is_space(str) << '\n';
    }

    void example17()
    {
        constexpr std::string_view str{"HELLO"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string uppercase? " << std::boolalpha << strpy::is_upper(str) << '\n';
    }

    void example18()
    {
        constexpr std::string_view str{"123abcABC"};
        std::cout << "String: '" << str << "'\n";
        std::cout << "Are all characters in the string hexadecimal digits? " << std::boolalpha << strpy::is_xdigit(str)
                  << '\n';
    }

    void example19()
    {
        constexpr std::string_view str{"Hello, World!"};
        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Lowercase string: '" << strpy::to_lower(str) << "'\n";
    }

    void example20()
    {
        constexpr std::string_view str{"Hello, World!"};
        std::cout << "Original string: '" << str << "'\n";
        std::cout << "Uppercase string: '" << strpy::to_upper(str) << "'\n";
    }
}

int main()
{
    std::cout << "Example 1 (is_identifier)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (is_title)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (is_alnum)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (is_alpha)" << '\n';
    example4();
    std::cout << '\n';

    std::cout << "Example 5 (is_ascii)" << '\n';
    example5();
    std::cout << '\n';

    std::cout << "Example 6 (is_blank)" << '\n';
    example6();
    std::cout << '\n';

    std::cout << "Example 7 (is_cntrl)" << '\n';
    example7();
    std::cout << '\n';

    std::cout << "Example 8 (is_digit)" << '\n';
    example8();
    std::cout << '\n';

    std::cout << "Example 9 (is_empty_or_space)" << '\n';
    example9();
    std::cout << '\n';

    std::cout << "Example 10 (is_graph)" << '\n';
    example10();
    std::cout << '\n';

    std::cout << "Example 11 (is_lower)" << '\n';
    example11();
    std::cout << '\n';

    std::cout << "Example 12 (is_null_or_empty)" << '\n';
    example12();
    std::cout << '\n';

    std::cout << "Example 13 (is_null_or_space)" << '\n';
    example13();
    std::cout << '\n';

    std::cout << "Example 14 (is_printable)" << '\n';
    example14();
    std::cout << '\n';

    std::cout << "Example 15 (is_punct)" << '\n';
    example15();
    std::cout << '\n';

    std::cout << "Example 16 (is_space)" << '\n';
    example16();
    std::cout << '\n';

    std::cout << "Example 17 (is_upper)" << '\n';
    example17();
    std::cout << '\n';

    std::cout << "Example 18 (is_xdigit)" << '\n';
    example18();
    std::cout << '\n';

    std::cout << "Example 19 (to_lower)" << '\n';
    example19();
    std::cout << '\n';

    std::cout << "Example 20 (to_upper)" << '\n';
    example20();

    return 0;
}

// Program output:
//
// Example 1 (is_identifier)
// String: 'hello_world'
// Is the string a valid identifier? true
//
// Example 2 (is_title)
// String: 'Hello, World!'
// Is the string a titlecased string? true
//
// Example 3 (is_alnum)
// String: 'hello123'
// Are all characters in the string alphanumeric? true
//
// Example 4 (is_alpha)
// String: 'hello'
// Are all characters in the string alphabetic? true
//
// Example 5 (is_ascii)
// String: 'hello, world!'
// Are all characters in the string ASCII characters? true
//
// Example 6 (is_blank)
// String: ' \t'
// Are all characters in the string blank? true
//
// Example 7 (is_cntrl)
// String: '\n'
// Are all characters in the string control characters? true
//
// Example 8 (is_digit)
// String: '123'
// Are all characters in the string decimal digits? true
//
// Example 9 (is_empty_or_space)
// String: ' \t\n'
// Is the string empty or contains only whitespace characters? true
//
// Example 10 (is_graph)
// String: 'hello, world!'
// Are all characters in the string graphical characters? false
//
// Example 11 (is_lower)
// String: 'hello'
// Are all characters in the string lowercase? true
//
// Example 12 (is_null_or_empty)
// String: nullptr
// Is the string null or empty? true
//
// Example 13 (is_null_or_space)
// String: nullptr
// Is the string null, empty or contains only whitespace characters? true
//
// Example 14 (is_printable)
// String: 'hello, world!'
// Are all characters in the string printable characters? true
//
// Example 15 (is_punct)
// String: 'hello, world!'
// Are all characters in the string punctuation characters? false
//
// Example 16 (is_space)
// String: ' \t\n'
// Are all characters in the string whitespace characters? true
//
// Example 17 (is_upper)
// String: 'HELLO'
// Are all characters in the string uppercase? true
//
// Example 18 (is_xdigit)
// String: '123abcABC'
// Are all characters in the string hexadecimal digits? true
//
// Example 19 (to_lower)
// Original string: 'Hello, World!'
// Lowercase string: 'hello, world!'
//
// Example 20 (to_upper)
// Original string: 'Hello, World!'
// Uppercase string: 'HELLO, WORLD!'
