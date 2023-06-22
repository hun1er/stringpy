/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/capitalize.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(CapitalizeTest, Basic)
    {
        EXPECT_EQ(strpy::capitalize("hello"), "Hello");
        EXPECT_EQ(strpy::capitalize("HELLO"), "Hello");
        EXPECT_EQ(strpy::capitalize("Hello"), "Hello");
        EXPECT_EQ(strpy::capitalize("hELLO"), "Hello");
        EXPECT_EQ(strpy::capitalize("hello, and welcome to my world."), "Hello, and welcome to my world.");
        EXPECT_EQ(strpy::capitalize("python is FUN!"), "Python is fun!");
        EXPECT_EQ(strpy::capitalize("36 is my age."), "36 is my age.");
    }

    TEST(CapitalizeTest, EmptyString)
    {
        EXPECT_EQ(strpy::capitalize(""), "");
    }

    TEST(CapitalizeTest, SingleCharacter)
    {
        EXPECT_EQ(strpy::capitalize("h"), "H");
        EXPECT_EQ(strpy::capitalize("H"), "H");
    }

    TEST(CapitalizeTest, NonAlphabetic)
    {
        EXPECT_EQ(strpy::capitalize("123"), "123");
        EXPECT_EQ(strpy::capitalize("!@#"), "!@#");
    }

    TEST(CapitalizeTest, MixedCase)
    {
        EXPECT_EQ(strpy::capitalize("hElLo"), "Hello");
        EXPECT_EQ(strpy::capitalize("HeLLo"), "Hello");
    }

    TEST(CapitalizeTest, Whitespace)
    {
        EXPECT_EQ(strpy::capitalize(" hello"), " hello");
        EXPECT_EQ(strpy::capitalize("  hello"), "  hello");
        EXPECT_EQ(strpy::capitalize("\thello"), "\thello");
        EXPECT_EQ(strpy::capitalize("\nhello"), "\nhello");
    }

    TEST(CapitalizeTest, Punctuation)
    {
        EXPECT_EQ(strpy::capitalize(".hello"), ".hello");
        EXPECT_EQ(strpy::capitalize("!hello"), "!hello");
        EXPECT_EQ(strpy::capitalize("?hello"), "?hello");
    }

    TEST(CapitalizeTest, Sentences)
    {
        EXPECT_EQ(strpy::capitalize("hello world"), "Hello world");
        EXPECT_EQ(strpy::capitalize("HELLO WORLD"), "Hello world");
        EXPECT_EQ(strpy::capitalize("Hello World"), "Hello world");
        EXPECT_EQ(strpy::capitalize("hELLO wORLD"), "Hello world");
    }
}
