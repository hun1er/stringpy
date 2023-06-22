/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/swapcase.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(SwapcaseCharTest, Basic)
    {
        EXPECT_EQ(strpy::swap_case_char('a'), 'A');
        EXPECT_EQ(strpy::swap_case_char('z'), 'Z');
        EXPECT_EQ(strpy::swap_case_char('A'), 'a');
        EXPECT_EQ(strpy::swap_case_char('Z'), 'z');
    }

    TEST(SwapcaseCharTest, NonLetter)
    {
        EXPECT_EQ(strpy::swap_case_char('1'), '1');
        EXPECT_EQ(strpy::swap_case_char('.'), '.');
        EXPECT_EQ(strpy::swap_case_char(' '), ' ');
    }

    TEST(SwapcaseCharTest, SpecialCharacters)
    {
        EXPECT_EQ(strpy::swap_case_char('\n'), '\n');
        EXPECT_EQ(strpy::swap_case_char('\t'), '\t');
    }

    TEST(SwapcaseTest, Basic)
    {
        EXPECT_EQ(strpy::swap_case(""), "");
        EXPECT_EQ(strpy::swap_case("hello"), "HELLO");
        EXPECT_EQ(strpy::swap_case("WORLD"), "world");
        EXPECT_EQ(strpy::swap_case("Hello, World!"), "hELLO, wORLD!");
    }

    TEST(SwapcaseTest, NonLetterCharacters)
    {
        EXPECT_EQ(strpy::swap_case("12345"), "12345");
        EXPECT_EQ(strpy::swap_case("!@#$%^&*()"), "!@#$%^&*()");
    }

    TEST(SwapcaseTest, SpecialCharacters)
    {
        EXPECT_EQ(strpy::swap_case("\n\t\r"), "\n\t\r");
    }
}
