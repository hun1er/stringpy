/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/endswith.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(EndsWithTest, Basic)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::ends_with(str, "!"));
        EXPECT_TRUE(strpy::ends_with(str, "world!"));
        EXPECT_FALSE(strpy::ends_with(str, "hello"));
    }

    TEST(EndsWithTest, StartEnd)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::ends_with(str, "world!", 7));
        EXPECT_FALSE(strpy::ends_with(str, "world!", 8));
        EXPECT_TRUE(strpy::ends_with(str, "world!", 0, 13));
        EXPECT_FALSE(strpy::ends_with(str, "world!", 0, 12));
    }

    TEST(EndsWithTest, InvalidArguments)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::ends_with(str, "world", 20));
        EXPECT_FALSE(strpy::ends_with(str, "world", 0, 20));
    }

    TEST(EndsWithTest, EmptyString)
    {
        constexpr std::string_view str{};
        EXPECT_TRUE(strpy::ends_with(str, ""));
        EXPECT_FALSE(strpy::ends_with(str, "hello"));
    }

    TEST(EndsWithTest, EmptySuffix)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::ends_with(str, ""));
    }

    TEST(EndsWithTest, EqualStrings)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::ends_with(str, "Hello, world!"));
    }

    TEST(EndsWithTest, StartEndEqual)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::ends_with(str, "world", 7, 7));
    }

    TEST(EndsWithTest, StartGreaterThanEnd)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::ends_with(str, "world", 8, 7));
    }

    TEST(EndsWithTest, UnicodeTest)
    {
        constexpr std::string_view str{u8"Привет, мир!"};
        EXPECT_TRUE(strpy::ends_with(str, u8"мир!"));
        EXPECT_FALSE(strpy::ends_with(str, u8"Мир!"));
    }

    TEST(EndsWithTest, CaseSensitiveTest)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::ends_with(str, "World!"));
    }

    TEST(EndsWithTest, SpecialCharactersTest)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::ends_with(str, "!"));
        EXPECT_FALSE(strpy::ends_with(str, "?"));
    }

    TEST(EndsWithICaseTest, Basic)
    {
        constexpr std::string_view str{"HELlo, wORlD!"};
        EXPECT_TRUE(strpy::ends_with_icase(str, "!"));
        EXPECT_TRUE(strpy::ends_with_icase(str, "WoRLD!"));
        EXPECT_FALSE(strpy::ends_with_icase(str, "hEllO"));
    }

    TEST(EndsWithICaseTest, StartEnd)
    {
        constexpr std::string_view str{"HEllO, wORLD!"};
        EXPECT_TRUE(strpy::ends_with_icase(str, "wORlD!", 7));
        EXPECT_FALSE(strpy::ends_with_icase(str, "wOrld!", 8));
        EXPECT_TRUE(strpy::ends_with_icase(str, "WorlD!", 0, 13));
        EXPECT_FALSE(strpy::ends_with_icase(str, "worlD!", 0, 12));
    }

    TEST(EndsWithICaseTest, InvalidArguments)
    {
        constexpr std::string_view str{"hElLo, World!"};
        EXPECT_FALSE(strpy::ends_with_icase(str, "world", 20));
        EXPECT_FALSE(strpy::ends_with_icase(str, "wORlD", 0, 20));
    }

    TEST(EndsWithICaseTest, EmptyString)
    {
        constexpr std::string_view str{};
        EXPECT_TRUE(strpy::ends_with_icase(str, ""));
        EXPECT_FALSE(strpy::ends_with_icase(str, "HellO"));
    }

    TEST(EndsWithICaseTest, EmptySuffix)
    {
        constexpr std::string_view str{"HeLLo, WOrLD!"};
        EXPECT_TRUE(strpy::ends_with_icase(str, ""));
    }

    TEST(EndsWithICaseTest, EqualStrings)
    {
        constexpr std::string_view str{"HeLLo, wORlD!"};
        EXPECT_TRUE(strpy::ends_with_icase(str, "heLlo, WOrlD!"));
    }

    TEST(EndsWithICaseTest, StartEndEqual)
    {
        constexpr std::string_view str{"HElLo, WoRLd!"};
        EXPECT_FALSE(strpy::ends_with_icase(str, "wOrLD", 7, 7));
    }

    TEST(EndsWithICaseTest, StartGreaterThanEnd)
    {
        constexpr std::string_view str{"hEllo, woRld!"};
        EXPECT_FALSE(strpy::ends_with_icase(str, "woRlD", 8, 7));
    }

    TEST(EndsWithICaseTest, SpecialCharactersTest)
    {
        constexpr std::string_view str{"hELlo, woRlD!"};
        EXPECT_TRUE(strpy::ends_with_icase(str, "!"));
        EXPECT_FALSE(strpy::ends_with_icase(str, "?"));
    }
}
