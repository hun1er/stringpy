/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/translate.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(MakeTransTest, Basic)
    {
        auto trans_map = strpy::make_trans("abc", "def", "xyz");
        EXPECT_EQ(trans_map['a'], 'd');
        EXPECT_EQ(trans_map['b'], 'e');
        EXPECT_EQ(trans_map['c'], 'f');
        EXPECT_EQ(trans_map['x'], strpy::EOS);
        EXPECT_EQ(trans_map['y'], strpy::EOS);
        EXPECT_EQ(trans_map['z'], strpy::EOS);
    }

    TEST(MakeTransTest, EmptyFromTo)
    {
        auto trans_map = strpy::make_trans(strpy::EMPTY_STR, strpy::EMPTY_STR, "xyz");
        EXPECT_EQ(trans_map['x'], strpy::EOS);
        EXPECT_EQ(trans_map['y'], strpy::EOS);
        EXPECT_EQ(trans_map['z'], strpy::EOS);
    }

    TEST(MakeTransTest, EmptyDeleteChars)
    {
        auto trans_map = strpy::make_trans("abc", "def");
        EXPECT_EQ(trans_map['a'], 'd');
        EXPECT_EQ(trans_map['b'], 'e');
        EXPECT_EQ(trans_map['c'], 'f');
    }

    TEST(MakeTransTest, EmptyAll)
    {
        const auto& trans_map = strpy::make_trans(strpy::EMPTY_STR, strpy::EMPTY_STR);
        EXPECT_TRUE(trans_map.empty());
    }

    TEST(MakeTransTest, SingleChar)
    {
        auto trans_map = strpy::make_trans("a", "d", "x");
        EXPECT_EQ(trans_map['a'], 'd');
        EXPECT_EQ(trans_map['x'], strpy::EOS);
    }

    TEST(MakeTransTest, OverlappingFromTo)
    {
        auto trans_map = strpy::make_trans("abc", "bcd");
        EXPECT_EQ(trans_map['a'], 'b');
        EXPECT_EQ(trans_map['b'], 'c');
        EXPECT_EQ(trans_map['c'], 'd');
    }

    TEST(MakeTransTest, OverlappingFromDeleteChars)
    {
        auto trans_map = strpy::make_trans("abc", "def", "ac");
        EXPECT_EQ(trans_map['a'], strpy::EOS);
        EXPECT_EQ(trans_map['b'], 'e');
        EXPECT_EQ(trans_map['c'], strpy::EOS);
    }

    TEST(TranslateTest, Basic)
    {
        auto trans_map = strpy::make_trans("abc", "def", "xyz");
        constexpr std::string_view str{"abcdefxyz"};
        EXPECT_EQ(strpy::translate(str, trans_map), "defdef");

        trans_map = strpy::make_trans("mSa", "eJo", "odnght");
        EXPECT_EQ(strpy::translate("Good night Sam!", trans_map), "G i Joe!");
    }

    TEST(TranslateTest, EmptyStr)
    {
        const auto& trans_map = strpy::make_trans("abc", "def", "xyz");
        constexpr std::string_view str{};
        EXPECT_EQ(strpy::translate(str, trans_map), strpy::EMPTY_STR);
    }

    TEST(TranslateTest, EmptyTransMap)
    {
        const auto& trans_map = strpy::make_trans(strpy::EMPTY_STR, strpy::EMPTY_STR);
        constexpr std::string_view str{"abcdefxyz"};
        EXPECT_EQ(strpy::translate(str, trans_map), "abcdefxyz");
    }

    TEST(TranslateTest, SingleChar)
    {
        const auto& trans_map = strpy::make_trans("a", "d", "x");
        constexpr std::string_view str{"ax"};
        EXPECT_EQ(strpy::translate(str, trans_map), "d");
    }

    TEST(TranslateTest, OverlappingFromTo)
    {
        const auto& trans_map = strpy::make_trans("abc", "bcd");
        constexpr std::string_view str{"abc"};
        EXPECT_EQ(strpy::translate(str, trans_map), "bcd");
    }

    TEST(TranslateTest, OverlappingFromDeleteChars)
    {
        const auto& trans_map = strpy::make_trans("abc", "def", "ac");
        constexpr std::string_view str{"abc"};
        EXPECT_EQ(strpy::translate(str, trans_map), "e");
    }
}
