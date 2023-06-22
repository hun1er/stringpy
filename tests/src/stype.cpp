/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/stype.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(IdentifierTest, ValidIdentifiers)
    {
        EXPECT_TRUE(strpy::is_identifier("valid"));
        EXPECT_TRUE(strpy::is_identifier("_valid"));
        EXPECT_TRUE(strpy::is_identifier("valid123"));
        EXPECT_TRUE(strpy::is_identifier("_valid123"));
    }

    TEST(IdentifierTest, InvalidIdentifiers)
    {
        EXPECT_FALSE(strpy::is_identifier(""));
        EXPECT_FALSE(strpy::is_identifier("1invalid"));
        EXPECT_FALSE(strpy::is_identifier("!invalid"));
    }

    TEST(TitleTest, ValidTitle)
    {
        EXPECT_TRUE(strpy::is_title("This Is A Titlecased String"));
        EXPECT_TRUE(strpy::is_title("!! @This Is A Titlecased String With Numbers 123 !!@  "));
        EXPECT_TRUE(strpy::is_title("!@2Hello!@#$%^&*()World"));
        EXPECT_TRUE(strpy::is_title("It's A Test"));
    }

    TEST(TitleTest, InvalidTitle)
    {
        EXPECT_FALSE(strpy::is_title("this is not a titlecased string"));
        EXPECT_FALSE(strpy::is_title("This Is Not a Titlecased String"));
        EXPECT_FALSE(strpy::is_title("!@2Hello!@#$%^&*()world"));
        EXPECT_FALSE(strpy::is_title("It's a Test"));
    }

    TEST(AlnumTest, ValidAlnum)
    {
        EXPECT_TRUE(strpy::is_alnum("abc123"));
        EXPECT_TRUE(strpy::is_alnum("ABC123"));
    }

    TEST(AlnumTest, InvalidAlnum)
    {
        EXPECT_FALSE(strpy::is_alnum(""));
        EXPECT_FALSE(strpy::is_alnum("!abc123"));
    }

    TEST(AlphaTest, ValidAlpha)
    {
        EXPECT_TRUE(strpy::is_alpha("abc"));
        EXPECT_TRUE(strpy::is_alpha("ABC"));
    }

    TEST(AlphaTest, InvalidAlpha)
    {
        EXPECT_FALSE(strpy::is_alpha(""));
        EXPECT_FALSE(strpy::is_alpha("abc123"));
    }

    TEST(AsciiTest, ValidAscii)
    {
        EXPECT_TRUE(strpy::is_ascii(""));
        EXPECT_TRUE(strpy::is_ascii("abc123"));
    }

    TEST(AsciiTest, InvalidAscii)
    {
        EXPECT_FALSE(strpy::is_ascii("abc\x80"));
    }

    TEST(BlankTest, ValidBlank)
    {
        EXPECT_TRUE(strpy::is_blank("  "));
        EXPECT_TRUE(strpy::is_blank("\t\t"));
    }

    TEST(BlankTest, InvalidBlank)
    {
        EXPECT_FALSE(strpy::is_blank(""));
        EXPECT_FALSE(strpy::is_blank("abc123"));
    }

    TEST(CntrlTest, ValidCntrl)
    {
        EXPECT_TRUE(strpy::is_cntrl("\a\b\f\n\r\t\v"));
    }

    TEST(CntrlTest, InvalidCntrl)
    {
        EXPECT_FALSE(strpy::is_cntrl(""));
        EXPECT_FALSE(strpy::is_cntrl("abc123"));
    }

    TEST(DigitTest, ValidDigit)
    {
        EXPECT_TRUE(strpy::is_digit("123"));
    }

    TEST(DigitTest, InvalidDigit)
    {
        EXPECT_FALSE(strpy::is_digit(""));
        EXPECT_FALSE(strpy::is_digit("abc123"));
    }

    TEST(EmptyOrSpaceTest, ValidEmptySpace)
    {
        EXPECT_TRUE(strpy::is_empty_or_space(""));
        EXPECT_TRUE(strpy::is_empty_or_space(" \t\n"));
    }

    TEST(EmptyOrEmpty, InvalidEmptySpace)
    {
        EXPECT_FALSE(strpy::is_empty_or_space("abc123"));
    }

    TEST(GraphTest, ValidGraph)
    {
        EXPECT_TRUE(strpy::is_graph("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"));
    }

    TEST(GraphTest, InvalidGraph)
    {
        EXPECT_FALSE(strpy::is_graph(""));
        EXPECT_FALSE(strpy::is_graph(" "));
    }

    TEST(ToLowerTest, ValidLower)
    {
        EXPECT_TRUE(strpy::is_lower("abc"));
    }

    TEST(ToLowerTest, InvalidLower)
    {
        EXPECT_FALSE(strpy::is_lower(""));
        EXPECT_FALSE(strpy::is_lower("ABC"));
    }

    TEST(NullOrEmptyTest, ValidNullEmpty)
    {
        EXPECT_TRUE(strpy::is_null_or_empty(static_cast<char*>(nullptr)));
        EXPECT_TRUE(strpy::is_null_or_empty(""));
    }

    TEST(NullOrEmptyTest, InvalidNullEmpty)
    {
        EXPECT_FALSE(strpy::is_null_or_empty("abc123"));
    }

    TEST(NullOrSpaceTest, ValidNullSpace)
    {
        EXPECT_TRUE(strpy::is_null_or_space(static_cast<char*>(nullptr)));
        EXPECT_TRUE(strpy::is_null_or_space(""));
        EXPECT_TRUE(strpy::is_null_or_space(" \t\n"));
    }

    TEST(NullOrSpaceTest, InvalidNullSpace)
    {
        EXPECT_FALSE(strpy::is_null_or_space("abc123"));
    }

    TEST(PrintableTest, ValidPrintable)
    {
        EXPECT_TRUE(strpy::is_printable(""));
        EXPECT_TRUE(strpy::is_printable("abc123"));
    }

    TEST(PrintableTest, InvalidPrintable)
    {
        EXPECT_FALSE(strpy::is_printable("abc\x7F"));
    }

    TEST(PunctTest, ValidPunct)
    {
        EXPECT_TRUE(strpy::is_punct("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"));
    }

    TEST(PunctTest, InvalidPunct)
    {
        EXPECT_FALSE(strpy::is_punct(""));
        EXPECT_FALSE(strpy::is_punct("abc123"));
    }

    TEST(SpaceTest, ValidSpace)
    {
        EXPECT_TRUE(strpy::is_space(" \t\n"));
    }

    TEST(SpaceTest, InvalidSpace)
    {
        EXPECT_FALSE(strpy::is_space(""));
        EXPECT_FALSE(strpy::is_space("abc123"));
    }

    TEST(ToUpperTest, ValidUpper)
    {
        EXPECT_TRUE(strpy::is_upper("ABC"));
    }

    TEST(ToUpperTest, InvalidUpper)
    {
        EXPECT_FALSE(strpy::is_upper(""));
        EXPECT_FALSE(strpy::is_upper("abc"));
    }

    TEST(XdigitTest, ValidXdigit)
    {
        EXPECT_TRUE(strpy::is_xdigit("0123456789abcdefABCDEF"));
    }

    TEST(XdigitTest, InvalidXdigit)
    {
        EXPECT_FALSE(strpy::is_xdigit(""));
        EXPECT_FALSE(strpy::is_xdigit("xyz"));
    }

    TEST(ToLowerTest, Basic)
    {
        EXPECT_EQ(strpy::to_lower("HELLO"), "hello");
        EXPECT_EQ(strpy::to_lower("WORLD"), "world");
    }

    TEST(ToLowerTest, EmptyString)
    {
        EXPECT_EQ(strpy::to_lower(""), "");
    }

    TEST(ToLowerTest, MixedCase)
    {
        EXPECT_EQ(strpy::to_lower("HeLLo WoRLD"), "hello world");
    }

    TEST(ToLowerTest, NonAlphabeticCharacters)
    {
        EXPECT_EQ(strpy::to_lower("12345!@#$%"), "12345!@#$%");
    }

    TEST(ToLowerTest, SingleCharacter)
    {
        EXPECT_EQ(strpy::to_lower("A"), "a");
        EXPECT_EQ(strpy::to_lower("Z"), "z");
    }

    TEST(ToLowerTest, LongString)
    {
        const std::string long_string(1000, 'A');
        const std::string expected(1000, 'a');
        EXPECT_EQ(strpy::to_lower(long_string), expected);
    }

    TEST(ToLowerTest, AlreadyLowercase)
    {
        EXPECT_EQ(strpy::to_lower("hello"), "hello");
        EXPECT_EQ(strpy::to_lower("world"), "world");
    }

    TEST(ToUpperTest, Basic)
    {
        EXPECT_EQ(strpy::to_upper("hello"), "HELLO");
        EXPECT_EQ(strpy::to_upper("world"), "WORLD");
    }

    TEST(ToUpperTest, EmptyString)
    {
        EXPECT_EQ(strpy::to_upper(""), "");
    }

    TEST(ToUpperTest, MixedCase)
    {
        EXPECT_EQ(strpy::to_upper("HeLLo WoRLD"), "HELLO WORLD");
    }

    TEST(ToUpperTest, NonAlphabeticCharacters)
    {
        EXPECT_EQ(strpy::to_upper("12345!@#$%"), "12345!@#$%");
    }

    TEST(ToUpperTest, SingleCharacter)
    {
        EXPECT_EQ(strpy::to_upper("a"), "A");
        EXPECT_EQ(strpy::to_upper("z"), "Z");
    }

    TEST(ToUpperTest, LongString)
    {
        const std::string long_string(1000, 'a');
        const std::string expected(1000, 'A');
        EXPECT_EQ(strpy::to_upper(long_string), expected);
    }

    TEST(ToUpperTest, AlreadyUppercase)
    {
        EXPECT_EQ(strpy::to_upper("HELLO"), "HELLO");
        EXPECT_EQ(strpy::to_upper("HELLO"), "HELLO");
    }
}
