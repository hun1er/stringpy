/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/count.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(CountTest, Basic)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count(str, sub), 3);
    }

    TEST(CountTest, StartEnd)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count(str, sub, 3), 2);
        EXPECT_EQ(strpy::count(str, sub, 3, 6), 1);
    }

    TEST(CountTest, EmptySubstr)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{};
        EXPECT_EQ(strpy::count(str, sub), 10);
    }

    TEST(CountTest, EmptyStr)
    {
        constexpr std::string_view str{};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count(str, sub), 0);
    }

    TEST(CountTest, NoMatch)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{"def"};
        EXPECT_EQ(strpy::count(str, sub), 0);
    }

    TEST(CountTest, InvalidStart)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count(str, sub, 100), 0);
    }

    TEST(CountTest, InvalidEnd)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count(str, sub, 0, 100), 3);
    }

    TEST(CountTest, StartGreaterThanEnd)
    {
        constexpr std::string_view str{"abcabcabc"};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count(str, sub, 6, 3), 0);
    }

    TEST(CountTest, OverlappingSubstr)
    {
        constexpr std::string_view str{"abababab"};
        constexpr std::string_view sub{"aba"};
        EXPECT_EQ(strpy::count(str, sub), 2);
    }

    TEST(CountICaseTest, Basic)
    {
        constexpr std::string_view str{"abCabcAbc"};
        constexpr std::string_view sub{"Abc"};
        EXPECT_EQ(strpy::count_icase(str, sub), 3);
    }

    TEST(CountICaseTest, StartEnd)
    {
        constexpr std::string_view str{"ABcABcaBc"};
        constexpr std::string_view sub{"abc"};
        EXPECT_EQ(strpy::count_icase(str, sub, 3), 2);
        EXPECT_EQ(strpy::count_icase(str, sub, 3, 6), 1);
    }

    TEST(CountICaseTest, EmptySubstr)
    {
        constexpr std::string_view str{"aBCABcAbC"};
        constexpr std::string_view sub{};
        EXPECT_EQ(strpy::count_icase(str, sub), 10);
    }

    TEST(CountICaseTest, EmptyStr)
    {
        constexpr std::string_view str{};
        constexpr std::string_view sub{"Abc"};
        EXPECT_EQ(strpy::count_icase(str, sub), 0);
    }

    TEST(CountICaseTest, NoMatch)
    {
        constexpr std::string_view str{"ABcabcabC"};
        constexpr std::string_view sub{"Def"};
        EXPECT_EQ(strpy::count_icase(str, sub), 0);
    }

    TEST(CountICaseTest, InvalidStart)
    {
        constexpr std::string_view str{"aBcABcABC"};
        constexpr std::string_view sub{"AbC"};
        EXPECT_EQ(strpy::count_icase(str, sub, 100), 0);
    }

    TEST(CountICaseTest, InvalidEnd)
    {
        constexpr std::string_view str{"AbcABcABc"};
        constexpr std::string_view sub{"ABC"};
        EXPECT_EQ(strpy::count_icase(str, sub, 0, 100), 3);
    }

    TEST(CountICaseTest, StartGreaterThanEnd)
    {
        constexpr std::string_view str{"aBcAbCabC"};
        constexpr std::string_view sub{"aBc"};
        EXPECT_EQ(strpy::count_icase(str, sub, 6, 3), 0);
    }

    TEST(CountICaseTest, OverlappingSubstr)
    {
        constexpr std::string_view str{"aBAbaBAB"};
        constexpr std::string_view sub{"AbA"};
        EXPECT_EQ(strpy::count_icase(str, sub), 2);
    }
}
