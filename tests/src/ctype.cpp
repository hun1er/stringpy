/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/ctype.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(AlnumCharTest, ValidAlnumChar)
    {
        EXPECT_TRUE(strpy::is_alnum_char('a'));
        EXPECT_TRUE(strpy::is_alnum_char('A'));
        EXPECT_TRUE(strpy::is_alnum_char('0'));
    }

    TEST(AlnumCharTest, InvalidAlnumChar)
    {
        EXPECT_FALSE(strpy::is_alnum_char('!'));
    }

    TEST(AlphaCharTest, ValidAlphaChar)
    {
        EXPECT_TRUE(strpy::is_alpha_char('a'));
        EXPECT_TRUE(strpy::is_alpha_char('A'));
    }

    TEST(AlphaCharTest, InvalidAlphaChar)
    {
        EXPECT_FALSE(strpy::is_alpha_char('0'));
    }

    TEST(AsciiCharTest, ValidAsciiChar)
    {
        EXPECT_TRUE(strpy::is_ascii_char('\0'));
        EXPECT_TRUE(strpy::is_ascii_char('\x7F'));
    }

    TEST(AsciiCharTest, InvalidAsciiChar)
    {
        EXPECT_FALSE(strpy::is_ascii_char('\x80'));
    }

    TEST(BlankCharTest, ValidBlankChar)
    {
        EXPECT_TRUE(strpy::is_blank_char(' '));
        EXPECT_TRUE(strpy::is_blank_char('\t'));
    }

    TEST(BlankCharTest, InvalidBlankChar)
    {
        EXPECT_FALSE(strpy::is_blank_char('\n'));
    }

    TEST(CntrlCharTest, ValidCntrlChar)
    {
        EXPECT_TRUE(strpy::is_cntrl_char('\0'));
        EXPECT_TRUE(strpy::is_cntrl_char('\x1F'));
    }

    TEST(CntrlCharTest, InvalidCntrlChar)
    {
        EXPECT_FALSE(strpy::is_cntrl_char(' '));
    }

    TEST(DigitCharTest, ValidDigitChar)
    {
        EXPECT_TRUE(strpy::is_digit_char('0'));
        EXPECT_TRUE(strpy::is_digit_char('9'));
    }

    TEST(DigitCharTest, InvalidDigitChar)
    {
        EXPECT_FALSE(strpy::is_digit_char('a'));
    }

    TEST(GraphCharTest, ValidGraphChar)
    {
        EXPECT_TRUE(strpy::is_graph_char('a'));
        EXPECT_TRUE(strpy::is_graph_char('A'));
        EXPECT_TRUE(strpy::is_graph_char('0'));
    }

    TEST(GraphCharTest, InvalidGraphChar)
    {
        EXPECT_FALSE(strpy::is_graph_char(' '));
    }

    TEST(LowerCharTest, ValidLowerChar)
    {
        EXPECT_TRUE(strpy::is_lower_char('a'));
        EXPECT_TRUE(strpy::is_lower_char('z'));
    }

    TEST(LowerCharTest, InvalidLowerChar)
    {
        EXPECT_FALSE(strpy::is_lower_char('A'));
    }

    TEST(PrintableCharTest, ValidPrintableChar)
    {
        EXPECT_TRUE(strpy::is_printable_char(' '));
        EXPECT_TRUE(strpy::is_printable_char('~'));
    }

    TEST(PrintableCharTest, InvalidPrintableChar)
    {
        EXPECT_FALSE(strpy::is_printable_char('\x7F'));
    }

    TEST(PunctCharTest, ValidPunctChar)
    {
        EXPECT_TRUE(strpy::is_punct_char('!'));
        EXPECT_TRUE(strpy::is_punct_char('/'));
    }

    TEST(PunctCharTest, InvalidPunctChar)
    {
        EXPECT_FALSE(strpy::is_punct_char(' '));
    }

    TEST(SpaceCharTest, ValidSpaceChar)
    {
        EXPECT_TRUE(strpy::is_space_char(' '));
        EXPECT_TRUE(strpy::is_space_char('\t'));
    }

    TEST(SpaceCharTest, InvalidSpaceChar)
    {
        EXPECT_FALSE(strpy::is_space_char('a'));
    }

    TEST(UpperCharTest, ValidUpperChar)
    {
        EXPECT_TRUE(strpy::is_upper_char('A'));
        EXPECT_TRUE(strpy::is_upper_char('Z'));
    }

    TEST(UpperCharTest, InvalidUpperChar)
    {
        EXPECT_FALSE(strpy::is_upper_char('a'));
    }

    TEST(XdigitCharTest, ValidXdigitChar)
    {
        EXPECT_TRUE(strpy::is_xdigit_char('0'));
        EXPECT_TRUE(strpy::is_xdigit_char('9'));
        EXPECT_TRUE(strpy::is_xdigit_char('a'));
        EXPECT_TRUE(strpy::is_xdigit_char('f'));
        EXPECT_TRUE(strpy::is_xdigit_char('A'));
        EXPECT_TRUE(strpy::is_xdigit_char('F'));
    }

    TEST(XdigitCharTest, InvalidXdigitChar)
    {
        EXPECT_FALSE(strpy::is_xdigit_char('g'));
    }

    TEST(ToLowerCharTest, Basic)
    {
        EXPECT_EQ(strpy::to_lower_char('A'), 'a');
        EXPECT_EQ(strpy::to_lower_char('Z'), 'z');
        EXPECT_EQ(strpy::to_lower_char('a'), 'a');
        EXPECT_EQ(strpy::to_lower_char('z'), 'z');
        EXPECT_EQ(strpy::to_lower_char('0'), '0');
        EXPECT_EQ(strpy::to_lower_char('9'), '9');
    }

    TEST(ToUpperCharTest, Basic)
    {
        EXPECT_EQ(strpy::to_upper_char('A'), 'A');
        EXPECT_EQ(strpy::to_upper_char('Z'), 'Z');
        EXPECT_EQ(strpy::to_upper_char('a'), 'A');
        EXPECT_EQ(strpy::to_upper_char('z'), 'Z');
        EXPECT_EQ(strpy::to_upper_char('0'), '0');
        EXPECT_EQ(strpy::to_upper_char('9'), '9');
    }
}
