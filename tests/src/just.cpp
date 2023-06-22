/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/just.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(LjustTest, Basic)
    {
        EXPECT_EQ(strpy::ljust("hello", 10), "hello     ");
        EXPECT_EQ(strpy::ljust("hello", 10, '*'), "hello*****");
        EXPECT_EQ(strpy::ljust("hello", 3), "hello");
        EXPECT_EQ(strpy::ljust("", 3), "   ");
        EXPECT_EQ(strpy::ljust("", 0), "");
    }

    TEST(LjustTest, EdgeCases)
    {
        EXPECT_EQ(strpy::ljust("hello", 0), "hello");
        EXPECT_EQ(strpy::ljust("hello", 5), "hello");
    }

    TEST(LjustTest, DifferentFillChars)
    {
        EXPECT_EQ(strpy::ljust("hello", 10, '*'), "hello*****");
        EXPECT_EQ(strpy::ljust("hello", 10, '-'), "hello-----");
        EXPECT_EQ(strpy::ljust("hello", 10, '_'), "hello_____");
    }

    TEST(LjustTest, LongStrings)
    {
        const std::string long_string(1000, 'a');
        const auto& result = strpy::ljust(long_string, 2000);
        EXPECT_EQ(result.size(), 2000);
        EXPECT_EQ(result.substr(0, 1000), long_string);
    }

    TEST(RjustTest, Basic)
    {
        EXPECT_EQ(strpy::rjust("hello", 10), "     hello");
        EXPECT_EQ(strpy::rjust("hello", 10, '*'), "*****hello");
        EXPECT_EQ(strpy::rjust("hello", 3), "hello");
        EXPECT_EQ(strpy::rjust("", 3), "   ");
        EXPECT_EQ(strpy::rjust("", 0), "");
    }

    TEST(RjustTest, EdgeCases)
    {
        EXPECT_EQ(strpy::rjust("hello", 0), "hello");
        EXPECT_EQ(strpy::rjust("hello", 5), "hello");
    }

    TEST(RjustTest, DifferentFillChars)
    {
        EXPECT_EQ(strpy::rjust("hello", 10, '*'), "*****hello");
        EXPECT_EQ(strpy::rjust("hello", 10, '-'), "-----hello");
        EXPECT_EQ(strpy::rjust("hello", 10, '_'), "_____hello");
    }

    TEST(RjustTest, LongStrings)
    {
        const std::string long_string(1000, 'a');
        const auto& result = strpy::rjust(long_string, 2000);
        EXPECT_EQ(result.size(), 2000);
        EXPECT_EQ(result.substr(1000), long_string);
    }

    TEST(ZFillTest, BasicTest)
    {
        EXPECT_EQ(strpy::zfill("hello", 10), "00000hello");
        EXPECT_EQ(strpy::zfill("welcome to the jungle", 10), "welcome to the jungle");
        EXPECT_EQ(strpy::zfill("10.000", 10), "000010.000");
        EXPECT_EQ(strpy::zfill("42", 4), "0042");
        EXPECT_EQ(strpy::zfill("42", 2), "42");
        EXPECT_EQ(strpy::zfill("42", 1), "42");
        EXPECT_EQ(strpy::zfill("", 4), "0000");
        EXPECT_EQ(strpy::zfill("", 0), "");
    }

    TEST(ZFillTest, LargeWidthTest)
    {
        const std::string large_str(1000, 'a');
        std::string expected_str(1000, '0');
        expected_str += large_str;
        EXPECT_EQ(strpy::zfill(large_str, 2000), expected_str);
    }

    TEST(ZFillTest, EdgeCasesTest)
    {
        EXPECT_EQ(strpy::zfill("42", 0), "42");
        EXPECT_EQ(strpy::zfill("", 0), "");
    }
}
