/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/startswith.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(StartsWithTest, Basic)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::starts_with(str, "H"));
        EXPECT_TRUE(strpy::starts_with(str, "Hello"));
        EXPECT_FALSE(strpy::starts_with(str, "hello"));
    }

    TEST(StartsWithTest, StartEnd)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::starts_with(str, "world", 7));
        EXPECT_FALSE(strpy::starts_with(str, "world", 8));
        EXPECT_TRUE(strpy::starts_with(str, "Hello", 0, 5));
        EXPECT_FALSE(strpy::starts_with(str, "Hello", 0, 4));
    }

    TEST(StartsWithTest, InvalidArguments)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::starts_with(str, "world", 20));
        EXPECT_FALSE(strpy::starts_with(str, "world", 0, 20));
    }

    TEST(StartsWithTest, EmptyString)
    {
        constexpr std::string_view str{};
        EXPECT_TRUE(strpy::starts_with(str, ""));
        EXPECT_FALSE(strpy::starts_with(str, "hello"));
    }

    TEST(StartsWithTest, EmptyPrefix)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::starts_with(str, ""));
    }

    TEST(StartsWithTest, EqualStrings)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::starts_with(str, "Hello, world!"));
    }

    TEST(StartsWithTest, StartEndEqual)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::starts_with(str, "world", 7, 7));
    }

    TEST(StartsWithTest, StartGreaterThanEnd)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::starts_with(str, "world", 8, 7));
    }

    TEST(StartsWithTest, UnicodeTest)
    {
        constexpr std::string_view str{u8"Привет, мир!"};
        EXPECT_TRUE(strpy::starts_with(str, u8"Привет"));
        EXPECT_FALSE(strpy::starts_with(str, u8"привет"));
    }

    TEST(StartsWithTest, CaseSensitiveTest)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_FALSE(strpy::starts_with(str, "hello"));
    }

    TEST(StartsWithTest, SpecialCharactersTest)
    {
        constexpr std::string_view str{"Hello, world!"};
        EXPECT_TRUE(strpy::starts_with(str, "H"));
        EXPECT_FALSE(strpy::starts_with(str, "?"));
    }

    TEST(StartsWithICaseTest, Basic)
    {
        constexpr std::string_view str{"HELlo, wORlD!"};
        EXPECT_TRUE(strpy::starts_with_icase(str, "h"));
        EXPECT_TRUE(strpy::starts_with_icase(str, "heLLo"));
        EXPECT_FALSE(strpy::starts_with_icase(str, "WOrlD"));
    }

    TEST(StartsWithICaseTest, StartEnd)
    {
        constexpr std::string_view str{"HEllO, wORLD!"};
        EXPECT_TRUE(strpy::starts_with_icase(str, "wORlD", 7));
        EXPECT_FALSE(strpy::starts_with_icase(str, "wOrld", 8));
        EXPECT_TRUE(strpy::starts_with_icase(str, "heLlo", 0, 5));
        EXPECT_FALSE(strpy::starts_with_icase(str, "heLlo", 0, 4));
    }

    TEST(StartsWithICaseTest, InvalidArguments)
    {
        constexpr std::string_view str{"hElLo, World!"};
        EXPECT_FALSE(strpy::starts_with_icase(str, "world", 20));
        EXPECT_FALSE(strpy::starts_with_icase(str, "wORlD", 0, 20));
    }

    TEST(StartsWithICaseTest, EmptyString)
    {
        constexpr std::string_view str{};
        EXPECT_TRUE(strpy::starts_with_icase(str, ""));
        EXPECT_FALSE(strpy::starts_with_icase(str, "HellO"));
    }

    TEST(StartsWithICaseTest, EmptyPrefix)
    {
        constexpr std::string_view str{"HeLLo, WOrLD!"};
        EXPECT_TRUE(strpy::starts_with_icase(str, ""));
    }

    TEST(StartsWithICaseTest, EqualStrings)
    {
        constexpr std::string_view str{"HeLLo, wORlD!"};
        EXPECT_TRUE(strpy::starts_with_icase(str, "heLlo, WOrlD!"));
    }

    TEST(StartsWithICaseTest, StartEndEqual)
    {
        constexpr std::string_view str{"HElLo, WoRLd!"};
        EXPECT_FALSE(strpy::starts_with_icase(str, "wOrLD", 7, 7));
    }

    TEST(StartsWithICaseTest, StartGreaterThanEnd)
    {
        constexpr std::string_view str{"hEllo, woRld!"};
        EXPECT_FALSE(strpy::starts_with_icase(str, "woRlD", 8, 7));
    }

    TEST(StartsWithICaseTest, SpecialCharactersTest)
    {
        constexpr std::string_view str{"hELlo, woRlD!"};
        EXPECT_TRUE(strpy::starts_with_icase(str, "h"));
        EXPECT_FALSE(strpy::starts_with_icase(str, "?"));
    }
}
