/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/ctype.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = '1';
        constexpr auto ch3 = '!';

        std::cout << "is_alnum_char('" << ch1 << "') = " << std::boolalpha << strpy::is_alnum_char(ch1) << '\n';
        std::cout << "is_alnum_char('" << ch2 << "') = " << std::boolalpha << strpy::is_alnum_char(ch2) << '\n';
        std::cout << "is_alnum_char('" << ch3 << "') = " << std::boolalpha << strpy::is_alnum_char(ch3) << '\n';
    }

    void example2()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = '1';
        constexpr auto ch3 = '!';

        std::cout << "is_alpha_char('" << ch1 << "') = " << std::boolalpha << strpy::is_alpha_char(ch1) << '\n';
        std::cout << "is_alpha_char('" << ch2 << "') = " << std::boolalpha << strpy::is_alpha_char(ch2) << '\n';
        std::cout << "is_alpha_char('" << ch3 << "') = " << std::boolalpha << strpy::is_alpha_char(ch3) << '\n';
    }

    void example3()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = '\x80';
        constexpr auto ch3 = '\x7F';

        std::cout << "is_ascii_char('" << ch1 << "') = " << std::boolalpha << strpy::is_ascii_char(ch1) << '\n';
        std::cout << "is_ascii_char('\\x80') = " << std::boolalpha << strpy::is_ascii_char(ch2) << '\n';
        std::cout << "is_ascii_char('\\x7F') = " << std::boolalpha << strpy::is_ascii_char(ch3) << '\n';
    }

    void example4()
    {
        constexpr auto ch1 = ' ';
        constexpr auto ch2 = '\t';
        constexpr auto ch3 = 'A';

        std::cout << "is_blank_char('" << ch1 << "') = " << std::boolalpha << strpy::is_blank_char(ch1) << '\n';
        std::cout << "is_blank_char('\\t') = " << std::boolalpha << strpy::is_blank_char(ch2) << '\n';
        std::cout << "is_blank_char('" << ch3 << "') = " << std::boolalpha << strpy::is_blank_char(ch3) << '\n';
    }

    void example5()
    {
        constexpr auto ch1 = '\0';
        constexpr auto ch2 = '\n';
        constexpr auto ch3 = 'A';

        std::cout << "is_cntrl_char('\\0') = " << std::boolalpha << strpy::is_cntrl_char(ch1) << '\n';
        std::cout << "is_cntrl_char('\\n') = " << std::boolalpha << strpy::is_cntrl_char(ch2) << '\n';
        std::cout << "is_cntrl_char('" << ch3 << "') = " << std::boolalpha << strpy::is_cntrl_char(ch3) << '\n';
    }

    void example6()
    {
        constexpr auto ch1 = '0';
        constexpr auto ch2 = '9';
        constexpr auto ch3 = 'A';

        std::cout << "is_digit_char('" << ch1 << "') = " << std::boolalpha << strpy::is_digit_char(ch1) << '\n';
        std::cout << "is_digit_char('" << ch2 << "') = " << std::boolalpha << strpy::is_digit_char(ch2) << '\n';
        std::cout << "is_digit_char('" << ch3 << "') = " << std::boolalpha << strpy::is_digit_char(ch3) << '\n';
    }

    void example7()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = ' ';
        constexpr auto ch3 = '\n';

        std::cout << "is_graph_char('" << ch1 << "') = " << std::boolalpha << strpy::is_graph_char(ch1) << '\n';
        std::cout << "is_graph_char('" << ch2 << "') = " << std::boolalpha << strpy::is_graph_char(ch2) << '\n';
        std::cout << "is_graph_char('\\n') = " << std::boolalpha << strpy::is_graph_char(ch3) << '\n';
    }

    void example8()
    {
        constexpr auto ch1 = 'a';
        constexpr auto ch2 = 'A';
        constexpr auto ch3 = '1';

        std::cout << "is_lower_char('" << ch1 << "') = " << std::boolalpha << strpy::is_lower_char(ch1) << '\n';
        std::cout << "is_lower_char('" << ch2 << "') = " << std::boolalpha << strpy::is_lower_char(ch2) << '\n';
        std::cout << "is_lower_char('" << ch3 << "') = " << std::boolalpha << strpy::is_lower_char(ch3) << '\n';
    }

    void example9()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = ' ';
        constexpr auto ch3 = '\n';

        std::cout << "is_printable_char('" << ch1 << "') = " << std::boolalpha << strpy::is_printable_char(ch1) << '\n';

        std::cout << "is_printable_char('" << ch2 << "') = " << std::boolalpha << strpy::is_printable_char(ch2) << '\n';

        std::cout << "is_printable_char('\\n') = " << std::boolalpha << strpy::is_printable_char(ch3) << '\n';
    }

    void example10()
    {
        constexpr auto ch1 = ',';
        constexpr auto ch2 = ' ';
        constexpr auto ch3 = 'A';

        std::cout << "is_punct_char('" << ch1 << "') = " << std::boolalpha << strpy::is_punct_char(ch1) << '\n';
        std::cout << "is_punct_char('" << ch2 << "') = " << std::boolalpha << strpy::is_punct_char(ch2) << '\n';
        std::cout << "is_punct_char('" << ch3 << "') = " << std::boolalpha << strpy::is_punct_char(ch3) << '\n';
    }

    void example11()
    {
        constexpr auto ch1 = ' ';
        constexpr auto ch2 = '\t';
        constexpr auto ch3 = 'A';

        std::cout << "is_space_char('" << ch1 << "') = " << std::boolalpha << strpy::is_space_char(ch1) << '\n';
        std::cout << "is_space_char('\\t') = " << std::boolalpha << strpy::is_space_char(ch2) << '\n';
        std::cout << "is_space_char('" << ch3 << "') = " << std::boolalpha << strpy::is_space_char(ch3) << '\n';
    }

    void example12()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = 'a';
        constexpr auto ch3 = '1';

        std::cout << "is_upper_char('" << ch1 << "') = " << std::boolalpha << strpy::is_upper_char(ch1) << '\n';
        std::cout << "is_upper_char('" << ch2 << "') = " << std::boolalpha << strpy::is_upper_char(ch2) << '\n';
        std::cout << "is_upper_char('" << ch3 << "') = " << std::boolalpha << strpy::is_upper_char(ch3) << '\n';
    }

    void example13()
    {
        constexpr auto ch1 = '0';
        constexpr auto ch2 = 'A';
        constexpr auto ch3 = 'G';

        std::cout << "is_xdigit_char('" << ch1 << "') = " << std::boolalpha << strpy::is_xdigit_char(ch1) << '\n';
        std::cout << "is_xdigit_char('" << ch2 << "') = " << std::boolalpha << strpy::is_xdigit_char(ch2) << '\n';
        std::cout << "is_xdigit_char('" << ch3 << "') = " << std::boolalpha << strpy::is_xdigit_char(ch3) << '\n';
    }

    void example14()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = 'a';

        std::cout << "to_lower_char('" << ch1 << "') = " << strpy::to_lower_char(ch1) << '\n';
        std::cout << "to_lower_char('" << ch2 << "') = " << strpy::to_lower_char(ch2) << '\n';
    }

    void example15()
    {
        constexpr auto ch1 = 'A';
        constexpr auto ch2 = 'a';

        std::cout << "to_upper_char('" << ch1 << "') = " << strpy::to_upper_char(ch1) << '\n';
        std::cout << "to_upper_char('" << ch2 << "') = " << strpy::to_upper_char(ch2) << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (is_alnum_char)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (is_alpha_char)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (is_ascii_char)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (is_blank_char)" << '\n';
    example4();
    std::cout << '\n';

    std::cout << "Example 5 (is_cntrl_char)" << '\n';
    example5();
    std::cout << '\n';

    std::cout << "Example 6 (is_digit_char)" << '\n';
    example6();
    std::cout << '\n';

    std::cout << "Example 7 (is_graph_char)" << '\n';
    example7();
    std::cout << '\n';

    std::cout << "Example 8 (is_lower_char)" << '\n';
    example8();
    std::cout << '\n';

    std::cout << "Example 9 (is_printable_char)" << '\n';
    example9();
    std::cout << '\n';

    std::cout << "Example 10 (is_punct_char)" << '\n';
    example10();
    std::cout << '\n';

    std::cout << "Example 11 (is_space_char)" << '\n';
    example11();
    std::cout << '\n';

    std::cout << "Example 12 (is_upper_char)" << '\n';
    example12();
    std::cout << '\n';

    std::cout << "Example 13 (is_xdigit_char)" << '\n';
    example13();
    std::cout << '\n';

    std::cout << "Example 14 (to_lower_char)" << '\n';
    example14();
    std::cout << '\n';

    std::cout << "Example 15 (to_upper_char)" << '\n';
    example15();

    return 0;
}

// Program output:
//
// Example 1 (is_alnum_char)
// is_alnum_char('A') = true
// is_alnum_char('1') = true
// is_alnum_char('!') = false
//
// Example 2 (is_alpha_char)
// is_alpha_char('A') = true
// is_alpha_char('1') = false
// is_alpha_char('!') = false
//
// Example 3 (is_ascii_char)
// is_ascii_char('A') = true
// is_ascii_char('\x80') = false
// is_ascii_char('\x7F') = true
//
// Example 4 (is_blank_char)
// is_blank_char(' ') = true
// is_blank_char('\t') = true
// is_blank_char('A') = false
//
// Example 5 (is_cntrl_char)
// is_cntrl_char('\0') = true
// is_cntrl_char('\n') = true
// is_cntrl_char('A') = false
//
// Example 6 (is_digit_char)
// is_digit_char('0') = true
// is_digit_char('9') = true
// is_digit_char('A') = false
//
// Example 7 (is_graph_char)
// is_graph_char('A') = true
// is_graph_char(' ') = false
// is_graph_char('\n') = false
//
// Example 8 (is_lower_char)
// is_lower_char('a') = true
// is_lower_char('A') = false
// is_lower_char('1') = false
//
// Example 9 (is_printable_char)
// is_printable_char('A') = true
// is_printable_char(' ') = true
// is_printable_char('\n') = false
//
// Example 10 (is_punct_char)
// is_punct_char(',') = true
// is_punct_char(' ') = false
// is_punct_char('A') = false
//
// Example 11 (is_space_char)
// is_space_char(' ') = true
// is_space_char('\t') = true
// is_space_char('A') = false
//
// Example 12 (is_upper_char)
// is_upper_char('A') = true
// is_upper_char('a') = false
// is_upper_char('1') = false
//
// Example 13 (is_xdigit_char)
// is_xdigit_char('0') = true
// is_xdigit_char('A') = true
// is_xdigit_char('G') = false
//
// Example 14 (to_lower_char)
// to_lower_char('A') = a
// to_lower_char('a') = a
//
// Example 15 (to_upper_char)
// to_upper_char('A') = A
// to_upper_char('a') = A
