/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/splitlines.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(SplitlinesTest, Basic)
    {
        constexpr std::string_view str{"Line 1\nLine 2\nLine 3\n"};
        const auto& result = strpy::split_lines(str);
        ASSERT_EQ(result.size(), 3);
        ASSERT_EQ(result[0], "Line 1");
        ASSERT_EQ(result[1], "Line 2");
        ASSERT_EQ(result[2], "Line 3");
    }

    TEST(SplitlinesTest, KeepEnds)
    {
        constexpr std::string_view str{"Line 1\nLine 2\nLine 3"};
        const auto& result = strpy::split_lines(str, true);
        ASSERT_EQ(result.size(), 3);
        ASSERT_EQ(result[0], "Line 1\n");
        ASSERT_EQ(result[1], "Line 2\n");
        ASSERT_EQ(result[2], "Line 3");
    }

    TEST(SplitlinesTest, EmptyString)
    {
        constexpr std::string_view str{};
        const auto& result = strpy::split_lines(str);
        ASSERT_EQ(result.size(), 0);
    }

    TEST(SplitlinesTest, SingleLine)
    {
        constexpr std::string_view str{"Hello, world!"};
        const auto& result = strpy::split_lines(str);
        ASSERT_EQ(result.size(), 1);
        ASSERT_EQ(result[0], str);
    }

    TEST(SplitlinesTest, EmptyLines)
    {
        constexpr std::string_view str{"\n\n"};
        const auto& result = strpy::split_lines(str);
        ASSERT_EQ(result.size(), 2);
        ASSERT_EQ(result[0], "");
        ASSERT_EQ(result[1], "");
    }

    TEST(SplitlinesTest, MixedNewlines)
    {
        auto result = strpy::split_lines("Line 1\r\nLine 2\nLine 3\r");
        ASSERT_EQ(result.size(), 3);
        ASSERT_EQ(result[0], "Line 1");
        ASSERT_EQ(result[1], "Line 2");
        ASSERT_EQ(result[2], "Line 3");

        result = strpy::split_lines("Line 1\r\nLine 2\nLine 3\r", true);
        ASSERT_EQ(result.size(), 3);
        ASSERT_EQ(result[0], "Line 1\r\n");
        ASSERT_EQ(result[1], "Line 2\n");
        ASSERT_EQ(result[2], "Line 3\r");

        result = strpy::split_lines("Line 1\r\n\r\r\n\n\n\r\rLine 2\nLine 3\r");
        ASSERT_EQ(result.size(), 9);
        ASSERT_EQ(result[0], "Line 1");
        ASSERT_EQ(result[1], "");
        ASSERT_EQ(result[2], "");
        ASSERT_EQ(result[3], "");
        ASSERT_EQ(result[4], "");
        ASSERT_EQ(result[5], "");
        ASSERT_EQ(result[6], "");
        ASSERT_EQ(result[7], "Line 2");
        ASSERT_EQ(result[8], "Line 3");

        result = strpy::split_lines("Line 1\r\n\r\r\n\n\n\r\rLine 2\nLine 3\r", true);
        ASSERT_EQ(result.size(), 9);
        ASSERT_EQ(result[0], "Line 1\r\n");
        ASSERT_EQ(result[1], "\r");
        ASSERT_EQ(result[2], "\r\n");
        ASSERT_EQ(result[3], "\n");
        ASSERT_EQ(result[4], "\n");
        ASSERT_EQ(result[5], "\r");
        ASSERT_EQ(result[6], "\r");
        ASSERT_EQ(result[7], "Line 2\n");
        ASSERT_EQ(result[8], "Line 3\r");
    }
}
