/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/title.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(TitleTest, Basic)
    {
        EXPECT_EQ(strpy::title(""), "");
        EXPECT_EQ(strpy::title("'"), "'");
        EXPECT_EQ(strpy::title("''"), "''");
        EXPECT_EQ(strpy::title("'''a"), "'''A");
        EXPECT_EQ(strpy::title("123"), "123");
        EXPECT_EQ(strpy::title("hello"), "Hello");
        EXPECT_EQ(strpy::title("hello world"), "Hello World");
        EXPECT_EQ(strpy::title("HELLO WORLD"), "Hello World");
        EXPECT_EQ(strpy::title("hello123world"), "Hello123world");
    }

    TEST(TitleTest, Punctuation)
    {
        EXPECT_EQ(strpy::title("hello, world!"), "Hello, World!");
        EXPECT_EQ(strpy::title("it's a test"), "It's A Test");
        EXPECT_EQ(strpy::title("don't stop"), "Don't Stop");
    }

    TEST(TitleTest, Whitespace)
    {
        EXPECT_EQ(strpy::title("  hello  world  "), "  Hello  World  ");
        EXPECT_EQ(strpy::title("\thello\tworld\t"), "\tHello\tWorld\t");
        EXPECT_EQ(strpy::title("\nhello\nworld\n"), "\nHello\nWorld\n");
    }

    TEST(TitleTest, MixedCase)
    {
        EXPECT_EQ(strpy::title("hELLo wORLd"), "Hello World");
        EXPECT_EQ(strpy::title("HeLLo WoRLD"), "Hello World");
    }

    TEST(TitleTest, NonAlphanumeric)
    {
        EXPECT_EQ(strpy::title("!@#$%^&*()"), "!@#$%^&*()");
        EXPECT_EQ(strpy::title("!@2hello!@#$%^&*()world"), "!@2Hello!@#$%^&*()World");
    }
}
