/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/strip.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(LstripTest, Basic)
    {
        EXPECT_EQ(strpy::lstrip<std::string>("   abc", ' '), "abc");
        EXPECT_EQ(strpy::lstrip<std::string>("abc   ", ' '), "abc   ");
        EXPECT_EQ(strpy::lstrip<std::string>("   abc   ", ' '), "abc   ");
        EXPECT_EQ(strpy::lstrip<std::string>("abc", ' '), "abc");
        EXPECT_EQ(strpy::lstrip<std::string>("", ' '), "");
    }

    TEST(LstripTest, DifferentCharacters)
    {
        EXPECT_EQ(strpy::lstrip<std::string>("...abc", '.'), "abc");
        EXPECT_EQ(strpy::lstrip<std::string>("abc...", '.'), "abc...");
        EXPECT_EQ(strpy::lstrip<std::string>("...abc...", '.'), "abc...");
        EXPECT_EQ(strpy::lstrip<std::string>("abc", '.'), "abc");
        EXPECT_EQ(strpy::lstrip<std::string>("", '.'), "");
    }

    TEST(LstripTest, DifferentReturnTypes)
    {
        EXPECT_EQ(strpy::lstrip("   abc", ' '), "abc");
        EXPECT_EQ(strpy::lstrip<std::string_view>("   abc", ' '), "abc");
    }

    TEST(LstripTest, NoLeadingCharacters)
    {
        EXPECT_EQ(strpy::lstrip<std::string>("abc", ' '), "abc");
        EXPECT_EQ(strpy::lstrip<std::string_view>("abc", ' '), "abc");
    }

    TEST(LstripTest, EmptyString)
    {
        EXPECT_EQ(strpy::lstrip(""), "");
        EXPECT_EQ(strpy::lstrip("", "abc"), "");
        EXPECT_EQ(strpy::lstrip<std::string>("", ' '), "");
        EXPECT_EQ(strpy::lstrip<std::string_view>("", ' '), "");
    }

    TEST(LstripTest, AllCharsStripped)
    {
        EXPECT_EQ(strpy::lstrip("abc", "abc"), "");
        EXPECT_EQ(strpy::lstrip("aaa", "a"), "");
        EXPECT_EQ(strpy::lstrip("abcabc", "abc"), "");
    }

    TEST(LstripTest, NoCharsStripped)
    {
        EXPECT_EQ(strpy::lstrip("abc", "def"), "abc");
        EXPECT_EQ(strpy::lstrip("Hello, world!", "xyz"), "Hello, world!");
    }

    TEST(LstripTest, OnlyLeadingCharsStripped)
    {
        EXPECT_EQ(strpy::lstrip("   Hello, world!", " "), "Hello, world!");
        EXPECT_EQ(strpy::lstrip("\t\t\tHello, world!", "\t"), "Hello, world!");
    }

    TEST(LstripTest, DefaultChars)
    {
        EXPECT_EQ(strpy::lstrip("   Hello, world!   "), "Hello, world!   ");
        EXPECT_EQ(strpy::lstrip("\tHello, world!\n"), "Hello, world!\n");
        EXPECT_EQ(strpy::lstrip("Hello, world!"), "Hello, world!");
        EXPECT_EQ(strpy::lstrip(""), "");
    }

    TEST(LstripTest, CustomChars)
    {
        EXPECT_EQ(strpy::lstrip("...Hello, world!...", "."), "Hello, world!...");
        EXPECT_EQ(strpy::lstrip("***Hello, world!***", "*"), "Hello, world!***");
        EXPECT_EQ(strpy::lstrip("Hello, world!", "*"), "Hello, world!");
        EXPECT_EQ(strpy::lstrip("", "*"), "");
    }

    TEST(LstripTest, StringView)
    {
        constexpr std::string_view str = "   Hello, world!   ";
        EXPECT_EQ(strpy::lstrip<std::string_view>(str), "Hello, world!   ");
    }

    TEST(LstripTest, OnlyStrippedChars)
    {
        EXPECT_EQ(strpy::lstrip("   "), "");
        EXPECT_EQ(strpy::lstrip("***", "*"), "");
    }

    TEST(RstripTest, Basic)
    {
        EXPECT_EQ(strpy::rstrip<std::string>("   abc", ' '), "   abc");
        EXPECT_EQ(strpy::rstrip<std::string>("abc   ", ' '), "abc");
        EXPECT_EQ(strpy::rstrip<std::string>("   abc   ", ' '), "   abc");
        EXPECT_EQ(strpy::rstrip<std::string>("abc", ' '), "abc");
        EXPECT_EQ(strpy::rstrip<std::string>("", ' '), "");
    }

    TEST(RstripTest, DifferentCharacters)
    {
        EXPECT_EQ(strpy::rstrip<std::string>("...abc", '.'), "...abc");
        EXPECT_EQ(strpy::rstrip<std::string>("abc...", '.'), "abc");
        EXPECT_EQ(strpy::rstrip<std::string>("...abc...", '.'), "...abc");
        EXPECT_EQ(strpy::rstrip<std::string>("abc", '.'), "abc");
        EXPECT_EQ(strpy::rstrip<std::string>("", '.'), "");
    }

    TEST(RstripTest, DifferentReturnTypes)
    {
        EXPECT_EQ(strpy::rstrip("abc   ", ' '), "abc");
        EXPECT_EQ(strpy::rstrip<std::string_view>("abc   ", ' '), "abc");
    }

    TEST(RstripTest, NoTrailingCharacters)
    {
        EXPECT_EQ(strpy::rstrip<std::string>("abc", ' '), "abc");
        EXPECT_EQ(strpy::rstrip<std::string_view>("abc", ' '), "abc");
    }

    TEST(RstripTest, EmptyString)
    {
        EXPECT_EQ(strpy::rstrip(""), "");
        EXPECT_EQ(strpy::rstrip("", "abc"), "");
        EXPECT_EQ(strpy::rstrip<std::string>("", ' '), "");
        EXPECT_EQ(strpy::rstrip<std::string_view>("", ' '), "");
    }

    TEST(RstripTest, AllCharsStripped)
    {
        EXPECT_EQ(strpy::rstrip("abc", "abc"), "");
        EXPECT_EQ(strpy::rstrip("aaa", "a"), "");
        EXPECT_EQ(strpy::rstrip("abcabc", "abc"), "");
    }

    TEST(RstripTest, NoCharsStripped)
    {
        EXPECT_EQ(strpy::rstrip("abc", "def"), "abc");
        EXPECT_EQ(strpy::rstrip("Hello, world!", "xyz"), "Hello, world!");
    }

    TEST(RstripTest, OnlyTrailingCharsStripped)
    {
        EXPECT_EQ(strpy::rstrip("Hello, world!   ", " "), "Hello, world!");
        EXPECT_EQ(strpy::rstrip("Hello, world!\t\t\t", "\t"), "Hello, world!");
    }

    TEST(RstripTest, DefaultChars)
    {
        EXPECT_EQ(strpy::rstrip("   Hello, world!   "), "   Hello, world!");
        EXPECT_EQ(strpy::rstrip("\tHello, world!\n"), "\tHello, world!");
        EXPECT_EQ(strpy::rstrip("Hello, world!"), "Hello, world!");
        EXPECT_EQ(strpy::rstrip(""), "");
    }

    TEST(RstripTest, CustomChars)
    {
        EXPECT_EQ(strpy::rstrip("...Hello, world!...", "."), "...Hello, world!");
        EXPECT_EQ(strpy::rstrip("***Hello, world!***", "*"), "***Hello, world!");
        EXPECT_EQ(strpy::rstrip("Hello, world!", "*"), "Hello, world!");
        EXPECT_EQ(strpy::rstrip("", "*"), "");
    }

    TEST(RstripTest, StringView)
    {
        constexpr std::string_view str = "   Hello, world!   ";
        EXPECT_EQ(strpy::rstrip<std::string_view>(str), "   Hello, world!");
    }

    TEST(RstripTest, OnlyStrippedChars)
    {
        EXPECT_EQ(strpy::rstrip("   "), "");
        EXPECT_EQ(strpy::rstrip("***", "*"), "");
    }

    TEST(StripTest, Basic)
    {
        EXPECT_EQ(strpy::strip<std::string>("   abc", ' '), "abc");
        EXPECT_EQ(strpy::strip<std::string>("abc   ", ' '), "abc");
        EXPECT_EQ(strpy::strip<std::string>("   abc   ", ' '), "abc");
        EXPECT_EQ(strpy::strip<std::string>("abc", ' '), "abc");
        EXPECT_EQ(strpy::strip<std::string>("", ' '), "");
    }

    TEST(StripTest, DifferentCharacters)
    {
        EXPECT_EQ(strpy::strip<std::string>("...abc", '.'), "abc");
        EXPECT_EQ(strpy::strip<std::string>("abc...", '.'), "abc");
        EXPECT_EQ(strpy::strip<std::string>("...abc...", '.'), "abc");
        EXPECT_EQ(strpy::strip<std::string>("abc", '.'), "abc");
        EXPECT_EQ(strpy::strip<std::string>("", '.'), "");
    }

    TEST(StripTest, DifferentReturnTypes)
    {
        EXPECT_EQ(strpy::strip("   abc   ", ' '), "abc");
        EXPECT_EQ(strpy::strip<std::string_view>("   abc   ", ' '), "abc");
    }

    TEST(StripTest, NoLeadingOrTrailingCharacters)
    {
        EXPECT_EQ(strpy::strip<std::string>("abc", ' '), "abc");
        EXPECT_EQ(strpy::strip<std::string_view>("abc", ' '), "abc");
    }

    TEST(StripTest, EmptyString)
    {
        EXPECT_EQ(strpy::strip(""), "");
        EXPECT_EQ(strpy::strip("", "abc"), "");
        EXPECT_EQ(strpy::strip<std::string>("", ' '), "");
        EXPECT_EQ(strpy::strip<std::string_view>("", ' '), "");
    }

    TEST(StripTest, AllCharsStripped)
    {
        EXPECT_EQ(strpy::strip("abc", "abc"), "");
        EXPECT_EQ(strpy::strip("aaa", "a"), "");
        EXPECT_EQ(strpy::strip("abcabc", "abc"), "");
    }

    TEST(StripTest, NoCharsStripped)
    {
        EXPECT_EQ(strpy::strip("abc", "def"), "abc");
        EXPECT_EQ(strpy::strip("Hello, world!", "xyz"), "Hello, world!");
    }

    TEST(StripTest, OnlyLeadingCharsStripped)
    {
        EXPECT_EQ(strpy::strip("   Hello, world!", " "), "Hello, world!");
        EXPECT_EQ(strpy::strip("\t\t\tHello, world!", "\t"), "Hello, world!");
    }

    TEST(StripTest, OnlyTrailingCharsStripped)
    {
        EXPECT_EQ(strpy::strip("Hello, world!   ", " "), "Hello, world!");
        EXPECT_EQ(strpy::strip("Hello, world!\t\t\t", "\t"), "Hello, world!");
    }

    TEST(StripTest, DefaultChars)
    {
        EXPECT_EQ(strpy::strip("   Hello, world!   "), "Hello, world!");
        EXPECT_EQ(strpy::strip("\tHello, world!\n"), "Hello, world!");
        EXPECT_EQ(strpy::strip("Hello, world!"), "Hello, world!");
        EXPECT_EQ(strpy::strip(""), "");
    }

    TEST(StripTest, CustomChars)
    {
        EXPECT_EQ(strpy::strip("...Hello, world!...", "."), "Hello, world!");
        EXPECT_EQ(strpy::strip("***Hello, world!***", "*"), "Hello, world!");
        EXPECT_EQ(strpy::strip("Hello, world!", "*"), "Hello, world!");
        EXPECT_EQ(strpy::strip("", "*"), "");
    }

    TEST(StripTest, StringView)
    {
        constexpr std::string_view str = "   Hello, world!   ";
        EXPECT_EQ(strpy::strip<std::string_view>(str), "Hello, world!");
    }

    TEST(StripTest, OnlyStrippedChars)
    {
        EXPECT_EQ(strpy::strip("   "), "");
        EXPECT_EQ(strpy::strip("***", "*"), "");
    }
}
