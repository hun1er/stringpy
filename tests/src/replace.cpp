/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/replace.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(ReplaceTest, Basic)
    {
        const std::string str = "one one was a race horse, two two was one too.";

        EXPECT_EQ(strpy::replace("hello world", "world", "there"), "hello there");
        EXPECT_EQ(strpy::replace("hello world world", "world", "there"), "hello there there");
        EXPECT_EQ(strpy::replace("hello world world", "world", "there", 1), "hello there world");
        EXPECT_EQ(strpy::replace("I like bananas", "bananas", "apples"), "I like apples");
        EXPECT_EQ(strpy::replace(str, "one", "three"), "three three was a race horse, two two was three too.");
        EXPECT_EQ(strpy::replace(str, "one", "three", 2), "three three was a race horse, two two was one too.");
    }

    TEST(ReplaceTest, NoReplacements)
    {
        EXPECT_EQ(strpy::replace("hello world", "test", "there"), "hello world");
        EXPECT_EQ(strpy::replace("hello world", "", "there"), "hello world");
    }

    TEST(ReplaceTest, EmptyString)
    {
        EXPECT_EQ(strpy::replace("", "world", "there"), "");
    }

    TEST(ReplaceTest, CountParameter)
    {
        EXPECT_EQ(strpy::replace("hello world world world", "world", "there", 2), "hello there there world");
        EXPECT_EQ(strpy::replace("hello world world world", "world", "there", 0), "hello world world world");
    }

    TEST(ReplaceTest, ReplaceWithEmptyString)
    {
        EXPECT_EQ(strpy::replace("hello world", "world", ""), "hello ");
    }

    TEST(ReplaceTest, ReplaceWithSubstring)
    {
        EXPECT_EQ(strpy::replace("aaa", "aa", "aaa"), "aaaa");
    }

    TEST(ReplaceTest, LargeCount)
    {
        EXPECT_EQ(strpy::replace("aaa", "a", "b", 100), "bbb");
    }

    TEST(ReplaceTest, ReplaceAtBeginning)
    {
        EXPECT_EQ(strpy::replace("hello world", "hello", "hi"), "hi world");
    }

    TEST(ReplaceTest, ReplaceAtEnd)
    {
        EXPECT_EQ(strpy::replace("hello world", "world", "there"), "hello there");
    }

    TEST(ReplaceTest, ReplaceInMiddle)
    {
        EXPECT_EQ(strpy::replace("hello brave world", "brave", "new"), "hello new world");
    }

    TEST(ReplaceTest, ReplaceMultipleOccurrences)
    {
        EXPECT_EQ(strpy::replace("hello world world world", "world", "there"), "hello there there there");
    }

    TEST(ReplaceTest, ReplaceWithLongerString)
    {
        EXPECT_EQ(strpy::replace("hello world", "world", "universe"), "hello universe");
    }

    TEST(ReplaceTest, ReplaceWithShorterString)
    {
        EXPECT_EQ(strpy::replace("hello universe", "universe", "world"), "hello world");
    }

    TEST(ReplaceICaseTest, Basic)
    {
        EXPECT_EQ(strpy::replace_icase("hello world", "WORLD", "there"), "hello there");
        EXPECT_EQ(strpy::replace_icase("hello world WORLD", "world", "there"), "hello there there");
        EXPECT_EQ(strpy::replace_icase("hello world WORLD", "world", "there", 1), "hello there WORLD");
    }

    TEST(ReplaceICaseTest, NoReplacements)
    {
        EXPECT_EQ(strpy::replace_icase("hello world", "test", "there"), "hello world");
        EXPECT_EQ(strpy::replace_icase("hello world", "", "there"), "hello world");
    }

    TEST(ReplaceICaseTest, EmptyString)
    {
        EXPECT_EQ(strpy::replace_icase("", "world", "there"), "");
    }

    TEST(ReplaceICaseTest, CountParameter)
    {
        EXPECT_EQ(strpy::replace_icase("hello world WORLD WORLD", "world", "there", 2), "hello there there WORLD");
        EXPECT_EQ(strpy::replace_icase("hello world WORLD WORLD", "world", "there", 0), "hello world WORLD WORLD");
    }

    TEST(ReplaceICaseTest, ReplaceWithEmptyString)
    {
        EXPECT_EQ(strpy::replace_icase("hello world", "WORLD", ""), "hello ");
    }

    TEST(ReplaceICaseTest, ReplaceAtBeginning)
    {
        EXPECT_EQ(strpy::replace_icase("hello world", "HELLO", "hi"), "hi world");
    }

    TEST(ReplaceICaseTest, ReplaceAtEnd)
    {
        EXPECT_EQ(strpy::replace_icase("hello world", "WORLD", "there"), "hello there");
    }

    TEST(ReplaceICaseTest, ReplaceInMiddle)
    {
        EXPECT_EQ(strpy::replace_icase("hello brave world", "BRAVE", "new"), "hello new world");
    }

    TEST(ReplaceICaseTest, ReplaceMultipleOccurrences)
    {
        EXPECT_EQ(strpy::replace_icase("hello world WORLD World", "world", "there"), "hello there there there");
    }

    TEST(ReplaceICaseTest, ReplaceWithLongerString)
    {
        EXPECT_EQ(strpy::replace_icase("hello world", "WORLD", "universe"), "hello universe");
    }

    TEST(ReplaceICaseTest, ReplaceWithShorterString)
    {
        EXPECT_EQ(strpy::replace_icase("hello universe", "UNIVERSE", "world"), "hello world");
    }
}
