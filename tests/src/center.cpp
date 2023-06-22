/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/center.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(CenterTest, BasicTest)
    {
        EXPECT_EQ(strpy::center("banana", 19, 'O'), "OOOOOOObananaOOOOOO");
        EXPECT_EQ(strpy::center("abc", 7), "  abc  ");
        EXPECT_EQ(strpy::center("abc", 7, '*'), "**abc**");
        EXPECT_EQ(strpy::center("abc", 6), "  abc ");
        EXPECT_EQ(strpy::center("abc", 6, '*'), "**abc*");
        EXPECT_EQ(strpy::center("abc", 3), "abc");
        EXPECT_EQ(strpy::center("abc", 2), "abc");
        EXPECT_EQ(strpy::center("", 3), "   ");
        EXPECT_EQ(strpy::center("", 3, '*'), "***");
        EXPECT_EQ(strpy::center("", 0, '*'), "");
    }

    TEST(CenterTest, EmptyString)
    {
        EXPECT_EQ(strpy::center("", 0), "");
        EXPECT_EQ(strpy::center("", 1), " ");
        EXPECT_EQ(strpy::center("", 1, '*'), "*");
        EXPECT_EQ(strpy::center("", 5), "     ");
        EXPECT_EQ(strpy::center("", 5, '*'), "*****");
    }

    TEST(CenterTest, NoPaddingNeeded)
    {
        EXPECT_EQ(strpy::center("abc", 0), "abc");
        EXPECT_EQ(strpy::center("abc", 1), "abc");
        EXPECT_EQ(strpy::center("abc", 2), "abc");
        EXPECT_EQ(strpy::center("abc", 3), "abc");
    }
}
