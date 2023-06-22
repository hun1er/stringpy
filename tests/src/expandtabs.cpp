/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/expandtabs.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(ExpandTabsTest, Basic)
    {
        EXPECT_EQ(strpy::expand_tabs("one\ttwo\nthree\tfour"), "one     two\nthree   four");
    }

    TEST(ExpandTabsTest, EmptyString)
    {
        EXPECT_EQ(strpy::expand_tabs(""), "");
    }

    TEST(ExpandTabsTest, NoTabs)
    {
        EXPECT_EQ(strpy::expand_tabs("abc"), "abc");
    }

    TEST(ExpandTabsTest, SingleTab)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb"), "a       b");
    }

    TEST(ExpandTabsTest, MultipleTabs)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb\tc"), "a       b       c");
    }

    TEST(ExpandTabsTest, CustomTabSize)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb", 4), "a   b");
    }

    TEST(ExpandTabsTest, NewLineReset)
    {
        EXPECT_EQ(strpy::expand_tabs("a\t\nb\tc"), "a       \nb       c");
    }

    TEST(ExpandTabsTest, CarriageReturnReset)
    {
        EXPECT_EQ(strpy::expand_tabs("a\t\rb\tc"), "a       \rb       c");
    }

    TEST(ExpandTabsTest, TabSizeZero)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb", 0), "ab");
    }

    TEST(ExpandTabsTest, TabSizeOne)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb", 1), "a b");
    }

    TEST(ExpandTabsTest, LargeTabSize)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb", 16), "a               b");
    }

    TEST(ExpandTabsTest, MixedContent)
    {
        EXPECT_EQ(strpy::expand_tabs("a\tb c\td"), "a       b c     d");
    }

    TEST(ExpandTabsTest, OnlyTabs)
    {
        EXPECT_EQ(strpy::expand_tabs("\t\t"), "                ");
    }
}
