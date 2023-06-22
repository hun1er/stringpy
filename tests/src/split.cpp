/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/split.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(SplitTest, Basic)
    {
        std::string_view str{"  one two   three\t\r\n"};
        std::vector<std::string> expected = {"one", "two", "three"};
        auto result = strpy::split(str);
        EXPECT_EQ(result, expected);

        str = "one,two,three";
        expected = {"one", "two", "three"};
        result = strpy::split(str, ",");
        EXPECT_EQ(result, expected);

        str = ",one,two,three,";
        expected = {"", "one", "two", "three", ""};
        result = strpy::split(str, ",");
        EXPECT_EQ(result, expected);

        result = strpy::split(str, ",", strpy::StringSplitOptions::trim);
        EXPECT_EQ(result, expected);

        expected = {",one,two,three,"};
        result = strpy::split(str, "");
        EXPECT_EQ(result, expected);

        expected = {"one", "two", "three"};
        result = strpy::split(str, ",", strpy::StringSplitOptions::remove_empty);
        EXPECT_EQ(result, expected);

        result = strpy::split(str, ",", strpy::StringSplitOptions::trim_remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(SplitTest, MaxSplit)
    {
        constexpr std::string_view str{"  one    two   three\t\r\n"};
        std::vector<std::string> expected = {"one", "   two   three\t\r\n"};
        auto result = strpy::split(str, 1);
        EXPECT_EQ(result, expected);

        expected = {"", " one    two   three\t\r\n"};
        result = strpy::split(str, " ", 1, strpy::StringSplitOptions::none);
        EXPECT_EQ(result, expected);

        expected = {"one", "   two   three\t\r\n"};
        result = strpy::split(str, " ", 1, strpy::StringSplitOptions::remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(SplitTest, EmptyString)
    {
        constexpr std::string_view str{};
        const std::vector<std::string> expected = {};
        auto result = strpy::split(str);
        EXPECT_EQ(result, expected);

        result = strpy::split(str, ",");
        EXPECT_EQ(result, expected);

        result = strpy::split(str, "");
        EXPECT_EQ(result, expected);
    }

    TEST(SplitTest, SpaceOnlyString)
    {
        constexpr std::string_view str{"   "};
        std::vector<std::string> expected = {};
        auto result = strpy::split(str);
        EXPECT_EQ(result, expected);

        expected = {"", "", "", ""};
        result = strpy::split(str, " ");
        EXPECT_EQ(result, expected);

        expected = {};
        result = strpy::split(str, " ", strpy::StringSplitOptions::trim_remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(SplitTest, InvalidMaxSplit)
    {
        constexpr std::string_view str = "one two three";
        const std::vector<std::string> expected = {"one two three"};
        auto result = strpy::split(str, 0);
        EXPECT_EQ(result, expected);

        result = strpy::split(str, "", strpy::StringSplitOptions::none);
        EXPECT_EQ(result, expected);

        result = strpy::split(str, "", 0, strpy::StringSplitOptions::trim_remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(RSplitTest, Basic)
    {
        std::string_view str{"  one two   three\t\r\n"};
        std::vector<std::string> expected = {"one", "two", "three"};
        auto result = strpy::rsplit(str);
        EXPECT_EQ(result, expected);

        str = "one,two,three";
        expected = {"one", "two", "three"};
        result = strpy::rsplit(str, ",");
        EXPECT_EQ(result, expected);

        str = ",one,two,three,";
        expected = {"", "one", "two", "three", ""};
        result = strpy::rsplit(str, ",");
        EXPECT_EQ(result, expected);

        result = strpy::rsplit(str, ",", strpy::StringSplitOptions::trim);
        EXPECT_EQ(result, expected);

        expected = {",one,two,three,"};
        result = strpy::rsplit(str, "");
        EXPECT_EQ(result, expected);

        expected = {"one", "two", "three"};
        result = strpy::rsplit(str, ",", strpy::StringSplitOptions::remove_empty);
        EXPECT_EQ(result, expected);

        result = strpy::rsplit(str, ",", strpy::StringSplitOptions::trim_remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(RSplitTest, MaxSplit)
    {
        constexpr std::string_view str{"\t\r\none    two   three  "};
        std::vector<std::string> expected = {"\t\r\none    two  ", "three"};
        auto result = strpy::rsplit(str, 1);
        EXPECT_EQ(result, expected);

        expected = {"\t\r\none    two   three ", ""};
        result = strpy::rsplit(str, " ", 1, strpy::StringSplitOptions::none);
        EXPECT_EQ(result, expected);

        expected = {"\t\r\none    two  ", "three"};
        result = strpy::rsplit(str, " ", 1, strpy::StringSplitOptions::remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(RSplitTest, EmptyString)
    {
        constexpr std::string_view str{};
        const std::vector<std::string> expected = {};
        auto result = strpy::rsplit(str);
        EXPECT_EQ(result, expected);

        result = strpy::rsplit(str, ",");
        EXPECT_EQ(result, expected);

        result = strpy::rsplit(str, "");
        EXPECT_EQ(result, expected);
    }

    TEST(RSplitTest, SpaceOnlyString)
    {
        constexpr std::string_view str{"   "};
        std::vector<std::string> expected = {};
        auto result = strpy::rsplit(str);
        EXPECT_EQ(result, expected);

        expected = {"", "", "", ""};
        result = strpy::rsplit(str, " ");
        EXPECT_EQ(result, expected);

        expected = {};
        result = strpy::rsplit(str, " ", strpy::StringSplitOptions::trim_remove_empty);
        EXPECT_EQ(result, expected);
    }

    TEST(RSplitTest, InvalidMaxSplit)
    {
        constexpr std::string_view str = "one two three";
        const std::vector<std::string> expected = {"one two three"};
        auto result = strpy::rsplit(str, 0);
        EXPECT_EQ(result, expected);

        result = strpy::rsplit(str, "", strpy::StringSplitOptions::none);
        EXPECT_EQ(result, expected);

        result = strpy::rsplit(str, "", 0, strpy::StringSplitOptions::trim_remove_empty);
        EXPECT_EQ(result, expected);
    }
}
