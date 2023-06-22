/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/format.hpp"
#include "stringpy/const.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(ToStringTest, Boolean)
    {
        EXPECT_EQ(strpy::to_string(true), "true");
        EXPECT_EQ(strpy::to_string(false), "false");
    }

    TEST(ToStringTest, Int)
    {
        EXPECT_EQ(strpy::to_string(42), "42");
    }

    TEST(ToStringTest, Double)
    {
        EXPECT_EQ(strpy::to_string(3.140), "3.14");
    }

    TEST(ToStringTest, StringView)
    {
        constexpr std::string_view value{"hello"};
        EXPECT_EQ(strpy::to_string(value), value);
    }

    TEST(ToStringTest, InitializerList)
    {
        EXPECT_EQ(strpy::to_string({}), strpy::EMPTY_STR);
        EXPECT_EQ(strpy::to_string({'a'}), "a");
        EXPECT_EQ(strpy::to_string({'h', 'e', 'l', 'l', 'o'}), "hello");
    }

    TEST(ToStringTest, EmptyString)
    {
        EXPECT_EQ(strpy::to_string(strpy::EMPTY_STR), strpy::EMPTY_STR);
    }

    TEST(ToStringTest, Nullptr)
    {
        constexpr char* value = nullptr;
        EXPECT_EQ(strpy::to_string(value), strpy::EMPTY_STR);
    }

    TEST(ToStringTest, Hex)
    {
        EXPECT_EQ(strpy::to_string(42, std::ios_base::hex), "2a");
    }

    TEST(ToStringTest, Octal)
    {
        EXPECT_EQ(strpy::to_string(42, std::ios_base::oct), "52");
    }

    TEST(FormatTest, Int)
    {
        constexpr auto a = 13;
        constexpr auto b = 50;
        const auto& result = strpy::format("The respondents of the survey were {}-{} years old.", a, b);
        EXPECT_EQ(result, "The respondents of the survey were 13-50 years old.");
    }

    TEST(FormatTest, BasicTypes)
    {
        constexpr char c = 'a';
        constexpr signed char sc = 'a';
        constexpr unsigned char uc = 'b';
        constexpr double d = 1.0;
        constexpr float f = 2.0F;
        constexpr int i = 1;
        constexpr long l = 1L;
        constexpr long double ld = 1.0L;
        constexpr long long ll = 2LL;
        constexpr short s = 1;
        constexpr unsigned short us = 2;
        constexpr unsigned int ui = 1;
        constexpr unsigned long ul = 2;
        constexpr unsigned long long ull = 2;

        EXPECT_EQ(strpy::format("{} {}", i, i + 1), "1 2");
        EXPECT_EQ(strpy::format("{} {}", c, 'b'), "a b");
        EXPECT_EQ(strpy::format("{} {}", sc, uc), "a b");
        EXPECT_EQ(strpy::format("{} {}", d, f), "1 2");
        EXPECT_EQ(strpy::format("{} {}", l, ll), "1 2");
        EXPECT_EQ(strpy::format("{} {}", ld, ld + 1), "1 2");
        EXPECT_EQ(strpy::format("{} {}", s, us), "1 2");
        EXPECT_EQ(strpy::format("{} {}", ui, ul), "1 2");
        EXPECT_EQ(strpy::format("{} {}", ull, ull + 1), "2 3");
    }

    TEST(FormatTest, String)
    {
        constexpr std::string_view a{"hello"};
        const std::string b{"world"};
        constexpr char* c = nullptr;
        EXPECT_EQ(strpy::format("{} {}{}", a, b, c), "hello world");
    }

    TEST(FormatTest, InitializerList)
    {
        const auto list_one = {'o', 'n', 'e'};
        const auto list_two = {'t', 'w', 'o'};
        const auto list_three = {'t', 'h', 'r', 'e', 'e'};
        const auto list_world = {'w', 'o', 'r', 'l', 'd'};

        EXPECT_EQ(strpy::format("Hello, {}!", list_world), "Hello, world!");
        EXPECT_EQ(strpy::format("{} + {} = {}", 1, list_two, 3), "1 + two = 3");
        EXPECT_EQ(strpy::format("{} + {} = {}", list_one, list_two, list_three), "one + two = three");
        EXPECT_EQ(strpy::format("Hello, world!", {}), "Hello, world!");
        EXPECT_EQ(strpy::format("Hello, {}!", {"world"}), "Hello, world!");

        const auto& result =
          strpy::format("{} + {} = {}", {strpy::to_string(1), strpy::to_string(2), strpy::to_string(3)});

        EXPECT_EQ(result, "1 + 2 = 3");
    }

    TEST(FormatTest, Braces)
    {
        EXPECT_EQ(strpy::format("Hello, World! {}"), "Hello, World! {}");
        EXPECT_EQ(strpy::format("The set is {{}, {}, {}}.", 1, 2, 3), "The set is {1, 2, 3}.");
    }

    TEST(FormatTest, MultiplePlaceholders)
    {
        EXPECT_EQ(strpy::format("{} {} {}", 1, 2, 3), "1 2 3");
        EXPECT_EQ(strpy::format("{} {} {} {} {}", 'a', 'b', 'c', 'd', 'e'), "a b c d e");
    }

    TEST(FormatTest, NoPlaceholders)
    {
        EXPECT_EQ(strpy::format("No placeholders", 1, 2, 3), "No placeholders");
    }

    TEST(FormatTest, NotEnoughPlaceholders)
    {
        EXPECT_EQ(strpy::format("Only one placeholder: {}", 1, 2, 3), "Only one placeholder: 1");
    }
}
