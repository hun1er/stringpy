/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/find.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(FindTest, Basic)
    {
        ASSERT_EQ(strpy::find("Hello, world!", "Hello"), 0);
        ASSERT_EQ(strpy::find("Hello, world!", "world"), 7);
        ASSERT_EQ(strpy::find("Hello, world!", "notfound"), std::string::npos);
    }

    TEST(FindTest, EmptyString)
    {
        ASSERT_EQ(strpy::find("", "world"), std::string::npos);
        ASSERT_EQ(strpy::find("Hello, world!", ""), 0);
        ASSERT_EQ(strpy::find("", ""), 0);
    }

    TEST(FindTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::find("Hello, world!", "world", 100), std::string::npos);
        ASSERT_EQ(strpy::find("Hello, world!", "world", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::find("Hello, world!", "world", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::find("Hello, world!", "world", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::find("Hello, world!", "world", 100, 100), std::string::npos);
    }

    TEST(FindTest, SentenceWithStart)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "jumps";
        ASSERT_EQ(strpy::find(str, sub, 16), 20);
    }

    TEST(FindTest, SentenceWithEnd)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "jumps";
        ASSERT_EQ(strpy::find(str, sub, 0, 25), 20);
    }

    TEST(FindTest, SentenceWithStartAndEnd)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "jumps";
        ASSERT_EQ(strpy::find(str, sub, 16, 25), 20);
    }

    TEST(FindTest, SentenceSubstringNotFoundWithStartAndEnd)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "cat";
        ASSERT_EQ(strpy::find(str, sub, 16, 25), std::string::npos);
    }

    TEST(FindICaseTest, Basic)
    {
        ASSERT_EQ(strpy::find_icase("hELLO, WOrLD!", "HellO"), 0);
        ASSERT_EQ(strpy::find_icase("helLo, WorLD!", "wORld"), 7);
        ASSERT_EQ(strpy::find_icase("HEllO, WORlD!", "NotfOuND"), std::string::npos);
    }

    TEST(FindICaseTest, EmptyString)
    {
        ASSERT_EQ(strpy::find_icase("", "WorLD"), std::string::npos);
        ASSERT_EQ(strpy::find_icase("hELLO, World!", ""), 0);
        ASSERT_EQ(strpy::find_icase("", ""), 0);
    }

    TEST(FindICaseTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::find_icase("heLlO, woRLD!", "wOrlD", 100), std::string::npos);
        ASSERT_EQ(strpy::find_icase("HelLo, WoRLd!", "wOrld", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::find_icase("hello, WoRLD!", "WorLd", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::find_icase("HElLo, WOrlD!", "WoRld", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::find_icase("HeLlO, WoRlD!", "WorLd", 100, 100), std::string::npos);
    }

    TEST(FindICaseTest, SentenceWithStart)
    {
        constexpr std::string_view str = "thE qUiCK bRowN fox JUMPS over tHe lazy dOg.";
        constexpr std::string_view sub = "JumPs";
        ASSERT_EQ(strpy::find_icase(str, sub, 16), 20);
    }

    TEST(FindICaseTest, SentenceWithEnd)
    {
        constexpr std::string_view str = "ThE QuicK BrOwN fox Jumps oVEr THE laZy DOG.";
        constexpr std::string_view sub = "JUMPS";
        ASSERT_EQ(strpy::find_icase(str, sub, 0, 25), 20);
    }

    TEST(FindICaseTest, SentenceWithStartAndEnd)
    {
        constexpr std::string_view str = "The qUIck BRown FOX jUmps Over tHe lazy doG.";
        constexpr std::string_view sub = "JUmPS";
        ASSERT_EQ(strpy::find_icase(str, sub, 16, 25), 20);
    }

    TEST(FindICaseTest, SentenceSubstringNotFoundWithStartAndEnd)
    {
        constexpr std::string_view str = "tHe quIcK BRown Fox JuMPs ovER tHe Lazy dog.";
        constexpr std::string_view sub = "cAt";
        ASSERT_EQ(strpy::find_icase(str, sub, 16, 25), std::string::npos);
    }

    TEST(RFindTest, Basic)
    {
        ASSERT_EQ(strpy::rfind("Hello, world!", "Hello"), 0);
        ASSERT_EQ(strpy::rfind("Hello, world!", "world"), 7);
        ASSERT_EQ(strpy::rfind("Hello, world!", "notfound"), std::string::npos);
        ASSERT_EQ(strpy::rfind("Hello, world! world!", "world"), 14);
        ASSERT_EQ(strpy::rfind("ababab", "aba"), 2);
        ASSERT_EQ(strpy::rfind("Hello, World!", "world!"), std::string::npos);
    }

    TEST(RFindTest, EmptyString)
    {
        ASSERT_EQ(strpy::rfind("", "world"), std::string::npos);
        ASSERT_EQ(strpy::rfind("Hello, world!", ""), 13);
        ASSERT_EQ(strpy::rfind("", ""), 0);
    }

    TEST(RFindTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::rfind("Hello, world!", "world", 100), std::string::npos);
        ASSERT_EQ(strpy::rfind("Hello, world!", "world", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::rfind("Hello, world!", "world", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::rfind("Hello, world!", "world", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::rfind("Hello, world!", "world", 100, 100), std::string::npos);
    }

    TEST(RFindTest, SentenceWithStart)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "jumps";
        ASSERT_EQ(strpy::rfind(str, sub, 16), 20);
    }

    TEST(RFindTest, SentenceWithEnd)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "jumps";
        ASSERT_EQ(strpy::rfind(str, sub, 0, 25), 20);
    }

    TEST(RFindTest, SentenceWithStartAndEnd)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "jumps";
        ASSERT_EQ(strpy::rfind(str, sub, 16, 25), 20);
    }

    TEST(RFindTest, SentenceSubstringNotFoundWithStartAndEnd)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        constexpr std::string_view sub = "cat";
        ASSERT_EQ(strpy::rfind(str, sub, 16, 25), std::string::npos);
    }

    TEST(RFindICaseTest, Basic)
    {
        ASSERT_EQ(strpy::rfind_icase("HELlO, woRLD!", "helLo"), 0);
        ASSERT_EQ(strpy::rfind_icase("hElLo, wOrld!", "WorLD"), 7);
        ASSERT_EQ(strpy::rfind_icase("HElLo, World!", "notFOUnd"), std::string::npos);
        ASSERT_EQ(strpy::rfind_icase("HEllO, wORLd! world!", "WOrLd"), 14);
        ASSERT_EQ(strpy::rfind_icase("aBAbaB", "abA"), 2);
    }

    TEST(RFindICaseTest, EmptyString)
    {
        ASSERT_EQ(strpy::rfind_icase("", "WOrLd"), std::string::npos);
        ASSERT_EQ(strpy::rfind_icase("hELLO, wOrlD!", ""), 13);
        ASSERT_EQ(strpy::rfind_icase("", ""), 0);
    }

    TEST(RFindICaseTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::rfind_icase("hEllo, WORLd!", "world", 100), std::string::npos);
        ASSERT_EQ(strpy::rfind_icase("HelLo, WoRLD!", "wOrld", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::rfind_icase("HellO, woRld!", "woRLd", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::rfind_icase("HElLO, woRLd!", "WoRld", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::rfind_icase("hELLO, WOrld!", "WOrlD", 100, 100), std::string::npos);
    }

    TEST(RFindICaseTest, SentenceWithStart)
    {
        constexpr std::string_view str = "tHe QuICK BROWn fOX JuMpS ovER tHE lAZy DoG.";
        constexpr std::string_view sub = "JUMPs";
        ASSERT_EQ(strpy::rfind_icase(str, sub, 16), 20);
    }

    TEST(RFindICaseTest, SentenceWithEnd)
    {
        constexpr std::string_view str = "the qUIcK BroWN fOX JUMPs OVeR the lazy doG.";
        constexpr std::string_view sub = "jumPS";
        ASSERT_EQ(strpy::rfind_icase(str, sub, 0, 25), 20);
    }

    TEST(RFindICaseTest, SentenceWithStartAndEnd)
    {
        constexpr std::string_view str = "THE quIck BROwN fox jUmPs OVER tHE LAZy DoG.";
        constexpr std::string_view sub = "JuMPS";
        ASSERT_EQ(strpy::rfind_icase(str, sub, 16, 25), 20);
    }

    TEST(RFindICaseTest, SentenceSubstringNotFoundWithStartAndEnd)
    {
        constexpr std::string_view str = "thE QUIcK BROwN Fox JuMPS Over THe lAzy DOg.";
        constexpr std::string_view sub = "cat";
        ASSERT_EQ(strpy::rfind_icase(str, sub, 16, 25), std::string::npos);
    }

    TEST(FindFirstOfTest, Basic)
    {
        constexpr std::string_view str = "Hello, world!";
        const std::string_view chars = "aeiou";
        ASSERT_EQ(strpy::find_first_of(str, chars), 1);
    }

    TEST(FindFirstOfTest, NoMatch)
    {
        constexpr std::string_view str = "Hello, world!";
        const std::string_view chars = "xyz";
        ASSERT_EQ(strpy::find_first_of(str, chars), std::string::npos);
    }

    TEST(FindFirstOfTest, StartEndPosition)
    {
        constexpr std::string_view str = "Hello, world!";
        const std::string_view chars = "aeiou";
        ASSERT_EQ(strpy::find_first_of(str, chars, 2), 4);
        ASSERT_EQ(strpy::find_first_of(str, chars, 2, 5), 4);
        ASSERT_EQ(strpy::find_first_of(str, chars, 2, 4), std::string::npos);
    }

    TEST(FindFirstOfTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::find_first_of("Hello, world!", "world", 100), std::string::npos);
        ASSERT_EQ(strpy::find_first_of("Hello, world!", "world", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::find_first_of("Hello, world!", "world", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::find_first_of("Hello, world!", "world", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::find_first_of("Hello, world!", "world", 100, 100), std::string::npos);
    }

    TEST(FindFirstOfICaseTest, Basic)
    {
        constexpr std::string_view str = "hELlo, WorLD!";
        const std::string_view chars = "aeIOu";
        ASSERT_EQ(strpy::find_first_of_icase(str, chars), 1);
    }

    TEST(FindFirstOfICaseTest, NoMatch)
    {
        constexpr std::string_view str = "HeLlO, WorlD!";
        const std::string_view chars = "xYz";
        ASSERT_EQ(strpy::find_first_of_icase(str, chars), std::string::npos);
    }

    TEST(FindFirstOfICaseTest, StartEndPosition)
    {
        constexpr std::string_view str = "heLlo, wORld!";
        const std::string_view chars = "AEIoU";
        ASSERT_EQ(strpy::find_first_of_icase(str, chars, 2), 4);
        ASSERT_EQ(strpy::find_first_of_icase(str, chars, 2, 5), 4);
        ASSERT_EQ(strpy::find_first_of_icase(str, chars, 2, 4), std::string::npos);
    }

    TEST(FindFirstOfICaseTest, EmptyString)
    {
        constexpr std::string_view str{};
        const std::string_view chars = "Aeiou";
        ASSERT_EQ(strpy::find_first_of_icase(str, chars), std::string::npos);
    }

    TEST(FindFirstOfICaseTest, EmptyChars)
    {
        constexpr std::string_view str = "HEllO, wORlD!";
        const std::string_view chars{};
        ASSERT_EQ(strpy::find_first_of_icase(str, chars), std::string::npos);
    }

    TEST(FindFirstOfICaseTest, EmptyStringAndChars)
    {
        constexpr std::string_view str{};
        const std::string_view chars{};
        ASSERT_EQ(strpy::find_first_of_icase(str, chars), std::string::npos);
    }

    TEST(FindFirstOfICaseTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::find_first_of_icase("hEllo, WORLd!", "world", 100), std::string::npos);
        ASSERT_EQ(strpy::find_first_of_icase("HelLo, WoRLD!", "wOrld", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::find_first_of_icase("HellO, woRld!", "woRLd", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::find_first_of_icase("HElLO, woRLd!", "WoRld", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::find_first_of_icase("hELLO, WOrld!", "WOrlD", 100, 100), std::string::npos);
    }

    TEST(FindFirstNotOfTest, Basic)
    {
        EXPECT_EQ(strpy::find_first_not_of("hello", "he"), 2);
        EXPECT_EQ(strpy::find_first_not_of("hello", "o"), 0);
        EXPECT_EQ(strpy::find_first_not_of("hello", "h"), 1);
        EXPECT_EQ(strpy::find_first_not_of("hello", "e"), 0);
    }

    TEST(FindFirstNotOfTest, StartArgument)
    {
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 1), 2);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 2), 2);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 3), 3);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 4), 4);
    }

    TEST(FindFirstNotOfTest, EndArgument)
    {
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 0, 5), 2);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 0, 4), 2);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 0, 2), std::string_view::npos);
    }

    TEST(FindFirstNotOfTest, StartAndEndArguments)
    {
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 0, 1), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of("hello world!", "o", 12, 12), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of("hello world!", "o", 4, 8), 5);
        EXPECT_EQ(strpy::find_first_not_of("hello world!", "", 0, 11), 0);
        EXPECT_EQ(strpy::find_first_not_of("hello world!", "z"), 0);
    }

    TEST(FindFirstNotOfTest, InvalidArguments)
    {
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 50), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 30, 5), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of("hello", "he", 0, 0), std::string_view::npos);
    }

    TEST(FindFirstNotOfTest, EmptyStrings)
    {
        EXPECT_EQ(strpy::find_first_not_of("l", ""), 0);
        EXPECT_EQ(strpy::find_first_not_of("hello", ""), 0);
        EXPECT_EQ(strpy::find_first_not_of("", ""), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of("", "l"), std::string_view::npos);
    }

    TEST(FindFirstNotOfTest, Sentences)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        const std::string_view chars = "aeiou";
        EXPECT_EQ(strpy::find_first_not_of(str, chars), 0);
        EXPECT_EQ(strpy::find_first_not_of(str, chars, 0, 10), 0);
        EXPECT_EQ(strpy::find_first_not_of(str, chars, 10), 10);
    }

    TEST(FindFirstNotOfICaseTest, Basic)
    {
        EXPECT_EQ(strpy::find_first_not_of_icase("hEllo", "He"), 2);
        EXPECT_EQ(strpy::find_first_not_of_icase("helLO", "o"), 0);
        EXPECT_EQ(strpy::find_first_not_of_icase("HelLo", "h"), 1);
        EXPECT_EQ(strpy::find_first_not_of_icase("HELlo", "e"), 0);
    }

    TEST(FindFirstNotOfICaseTest, StartArgument)
    {
        EXPECT_EQ(strpy::find_first_not_of_icase("HellO", "he", 1), 2);
        EXPECT_EQ(strpy::find_first_not_of_icase("hello", "He", 2), 2);
        EXPECT_EQ(strpy::find_first_not_of_icase("HeLLO", "hE", 3), 3);
        EXPECT_EQ(strpy::find_first_not_of_icase("Hello", "HE", 4), 4);
    }

    TEST(FindFirstNotOfICaseTest, EndArgument)
    {
        EXPECT_EQ(strpy::find_first_not_of_icase("HELlo", "He", 0, 5), 2);
        EXPECT_EQ(strpy::find_first_not_of_icase("heLlo", "HE", 0, 4), 2);
        EXPECT_EQ(strpy::find_first_not_of_icase("HeLlo", "he", 0, 2), std::string_view::npos);
    }

    TEST(FindFirstNotOfICaseTest, StartAndEndArguments)
    {
        EXPECT_EQ(strpy::find_first_not_of_icase("HEllO", "he", 0, 1), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of_icase("hELlO world!", "o", 12, 12), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of_icase("HelLo WoRLD!", "o", 4, 8), 5);
        EXPECT_EQ(strpy::find_first_not_of_icase("HeLLo WoRLd!", "", 0, 11), 0);
        EXPECT_EQ(strpy::find_first_not_of_icase("hElLo woRld!", "z"), 0);
    }

    TEST(FindFirstNotOfICaseTest, InvalidArguments)
    {
        EXPECT_EQ(strpy::find_first_not_of_icase("helLO", "he", 50), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of_icase("hello", "he", 30, 5), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of_icase("HELlo", "he", 0, 0), std::string_view::npos);
    }

    TEST(FindFirstNotOfICaseTest, EmptyStrings)
    {
        EXPECT_EQ(strpy::find_first_not_of_icase("l", ""), 0);
        EXPECT_EQ(strpy::find_first_not_of_icase("hElLO", ""), 0);
        EXPECT_EQ(strpy::find_first_not_of_icase("", ""), std::string_view::npos);
        EXPECT_EQ(strpy::find_first_not_of_icase("", "l"), std::string_view::npos);
    }

    TEST(FindFirstNotOfICaseTest, Sentences)
    {
        constexpr std::string_view str = "thE QuiCK BrOWN FOx JumPs OVeR The Lazy DOg.";
        const std::string_view chars = "aEIoU";
        EXPECT_EQ(strpy::find_first_not_of_icase(str, chars), 0);
        EXPECT_EQ(strpy::find_first_not_of_icase(str, chars, 0, 10), 0);
        EXPECT_EQ(strpy::find_first_not_of_icase(str, chars, 5, 10), 7);
    }

    TEST(FindLastOfTest, Basic)
    {
        EXPECT_EQ(strpy::find_last_of("hello", "l"), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "o"), 4);
        EXPECT_EQ(strpy::find_last_of("hello", "h"), 0);
        EXPECT_EQ(strpy::find_last_of("hello", "e"), 1);
    }

    TEST(FindLastOfTest, StartArgument)
    {
        EXPECT_EQ(strpy::find_last_of("hello", "l", 1), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 2), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 3), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 4), std::string_view::npos);
    }

    TEST(FindLastOfTest, EndArgument)
    {
        EXPECT_EQ(strpy::find_last_of("hello", "l", 0, 5), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 0, 4), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 0, 3), 2);
    }

    TEST(FindLastOfTest, StartAndEndArguments)
    {
        EXPECT_EQ(strpy::find_last_of("hello", "l", 1, 5), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 1, 4), 3);
        EXPECT_EQ(strpy::find_last_of("hello", "l", 1, 3), 2);
    }

    TEST(FindLastOfTest, InvalidArguments)
    {
        EXPECT_EQ(strpy::find_last_of("hello world!", "o", 0, 13), 7);
        EXPECT_EQ(strpy::find_last_of("hello world!", "o", 5, 4), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of("hello world!", "o", 12, 12), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of("hello world!", "", 0, 11), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of("hello world!", "z"), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of("hello world!", "o", 13, 13), std::string_view::npos);
    }

    TEST(FindLastOfTest, EmptyStrings)
    {
        EXPECT_EQ(strpy::find_last_of("", ""), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of("", "l"), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of("hello", ""), std::string_view::npos);
    }

    TEST(FindLastOfTest, Sentences)
    {
        constexpr std::string_view str{"The quick brown fox jumps over the lazy dog"};
        const std::string_view chars{"aeiou"};
        EXPECT_EQ(strpy::find_last_of(str, chars), 41);
        EXPECT_EQ(strpy::find_last_of(str, chars, 10), 41);
        EXPECT_EQ(strpy::find_last_of(str, chars, 0, 10), 6);
    }

    TEST(FindLastOfICaseTest, Basic)
    {
        EXPECT_EQ(strpy::find_last_of_icase("hEllo", "L"), 3);
        EXPECT_EQ(strpy::find_last_of_icase("HELlo", "o"), 4);
        EXPECT_EQ(strpy::find_last_of_icase("HELLo", "h"), 0);
        EXPECT_EQ(strpy::find_last_of_icase("HelLO", "E"), 1);
    }

    TEST(FindLastOfICaseTest, StartArgument)
    {
        EXPECT_EQ(strpy::find_last_of_icase("HELLo", "l", 1), 3);
        EXPECT_EQ(strpy::find_last_of_icase("hello", "L", 2), 3);
        EXPECT_EQ(strpy::find_last_of_icase("Hello", "l", 3), 3);
        EXPECT_EQ(strpy::find_last_of_icase("hEllo", "L", 4), std::string_view::npos);
    }

    TEST(FindLastOfICaseTest, EndArgument)
    {
        EXPECT_EQ(strpy::find_last_of_icase("heLLo", "l", 0, 5), 3);
        EXPECT_EQ(strpy::find_last_of_icase("HellO", "l", 0, 4), 3);
        EXPECT_EQ(strpy::find_last_of_icase("helLo", "l", 0, 3), 2);
    }

    TEST(FindLastOfICaseTest, StartAndEndArguments)
    {
        EXPECT_EQ(strpy::find_last_of_icase("HELlO", "l", 1, 5), 3);
        EXPECT_EQ(strpy::find_last_of_icase("hELLO", "l", 1, 4), 3);
        EXPECT_EQ(strpy::find_last_of_icase("hELlo", "l", 1, 3), 2);
    }

    TEST(FindLastOfICaseTest, InvalidArguments)
    {
        EXPECT_EQ(strpy::find_last_of_icase("HeLLo WORLd!", "o", 0, 13), 7);
        EXPECT_EQ(strpy::find_last_of_icase("HeLLo WoRlD!", "o", 5, 4), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of_icase("HELlo WOrlD!", "o", 12, 12), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of_icase("hellO WorLD!", "", 0, 11), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of_icase("heLLo wOrLD!", "z"), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of_icase("heLLo WORlD!", "o", 13, 13), std::string_view::npos);
    }

    TEST(FindLastOfICaseTest, EmptyStrings)
    {
        EXPECT_EQ(strpy::find_last_of_icase("", ""), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of_icase("", "l"), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_of_icase("hellO", ""), std::string_view::npos);
    }

    TEST(FindLastOfICaseTest, Sentences)
    {
        constexpr std::string_view str{"THE qUICK bROwn FOx JuMPs oveR tHe lAZy DOg"};
        const std::string_view chars{"AeiOu"};
        EXPECT_EQ(strpy::find_last_of_icase(str, chars), 41);
        EXPECT_EQ(strpy::find_last_of_icase(str, chars, 10), 41);
        EXPECT_EQ(strpy::find_last_of_icase(str, chars, 0, 10), 6);
    }

    TEST(FindLastNotOfTest, Basic)
    {
        EXPECT_EQ(strpy::find_last_not_of("hello", "he"), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "o"), 3);
        EXPECT_EQ(strpy::find_last_not_of("hello", "h"), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "e"), 4);
    }

    TEST(FindLastNotOfTest, StartArgument)
    {
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 1), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 2), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 3), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 4), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 5), std::string_view::npos);
    }

    TEST(FindLastNotOfTest, EndArgument)
    {
        EXPECT_EQ(strpy::find_last_not_of("", "o"), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of("hello world!", "o", 5, 4), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of("hello world!", "o", 12, 12), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of("hello world!", "", 0, 11), 10);
        EXPECT_EQ(strpy::find_last_not_of("hello world!", "z"), 11);
        EXPECT_EQ(strpy::find_last_not_of("hello world!", "o", 13, 13), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of("hello world!", "o", 0, 13), 11);
    }

    TEST(FindLastNotOfTest, StartAndEndArguments)
    {
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 1, 5), 4);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 1, 4), 3);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 1, 3), 2);
        EXPECT_EQ(strpy::find_last_not_of("hello", "he", 1, 2), std::string::npos);
    }

    TEST(FindLastNotOfTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::find_last_not_of("Hello, world!", "world", 100), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of("Hello, world!", "world", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of("Hello, world!", "world", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of("Hello, world!", "world", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of("Hello, world!", "world", 100, 100), std::string::npos);
    }

    TEST(FindLastNotOfTest, EmptyStrings)
    {
        EXPECT_EQ(strpy::find_last_not_of("hello", ""), 4);
        EXPECT_EQ(strpy::find_last_not_of("", ""), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of("", "l"), std::string_view::npos);
    }

    TEST(FindLastNotOfTest, Sentences)
    {
        constexpr std::string_view str = "The quick brown fox jumps over the lazy dog.";
        const std::string_view chars = "aeiou";
        EXPECT_EQ(strpy::find_last_not_of(str, chars), 43);
        EXPECT_EQ(strpy::find_last_not_of(str, chars, 10), 43);
        EXPECT_EQ(strpy::find_last_not_of(str, chars, 0, 10), 9);
    }

    TEST(FindLastNotOfICaseTest, Basic)
    {
        EXPECT_EQ(strpy::find_last_not_of_icase("HELLo", "he"), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("hELlO", "o"), 3);
        EXPECT_EQ(strpy::find_last_not_of_icase("hellO", "h"), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("heLLO", "e"), 4);
    }

    TEST(FindLastNotOfICaseTest, StartArgument)
    {
        EXPECT_EQ(strpy::find_last_not_of_icase("HelLo", "he", 1), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("hEllO", "he", 2), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("helLO", "he", 3), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("heLlo", "he", 4), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("HellO", "he", 5), std::string_view::npos);
    }

    TEST(FindLastNotOfICaseTest, EndArgument)
    {
        EXPECT_EQ(strpy::find_last_not_of_icase("", "o"), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of_icase("HellO WORlD!", "o", 5, 4), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of_icase("helLO WorLd!", "o", 12, 12), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of_icase("HellO WORLd!", "", 0, 11), 10);
        EXPECT_EQ(strpy::find_last_not_of_icase("HeLLo WOrld!", "z"), 11);
        EXPECT_EQ(strpy::find_last_not_of_icase("HeLLO WorLd!", "o", 13, 13), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of_icase("HeLLo WoRLD!", "o", 0, 13), 11);
    }

    TEST(FindLastNotOfICaseTest, StartAndEndArguments)
    {
        EXPECT_EQ(strpy::find_last_not_of_icase("HeLLo", "he", 1, 5), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("HEllo", "he", 1, 4), 3);
        EXPECT_EQ(strpy::find_last_not_of_icase("hELlO", "he", 1, 3), 2);
        EXPECT_EQ(strpy::find_last_not_of_icase("heLLo", "he", 1, 2), std::string::npos);
    }

    TEST(FindLastNotOfICaseTest, InvalidArguments)
    {
        ASSERT_EQ(strpy::find_last_not_of_icase("hELlo, WOrlD!", "wOrld", 100), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of_icase("heLLO, WOrld!", "WoRlD", 0, 0), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of_icase("HElLo, World!", "wOrLD", 7, 5), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of_icase("helLo, WoRld!", "woRld", 7, 7), std::string::npos);
        ASSERT_EQ(strpy::find_last_not_of_icase("hello, wORLd!", "wORld", 100, 100), std::string::npos);
    }

    TEST(FindLastNotOfICaseTest, EmptyStrings)
    {
        EXPECT_EQ(strpy::find_last_not_of_icase("hELlO", ""), 4);
        EXPECT_EQ(strpy::find_last_not_of_icase("", ""), std::string_view::npos);
        EXPECT_EQ(strpy::find_last_not_of_icase("", "l"), std::string_view::npos);
    }

    TEST(FindLastNotOfICaseTest, Sentences)
    {
        constexpr std::string_view str = "tHE QUick BrOWN FoX JUmps ovEr tHE lAZY DOg.";
        const std::string_view chars = "aEiOu";
        EXPECT_EQ(strpy::find_last_not_of_icase(str, chars), 43);
        EXPECT_EQ(strpy::find_last_not_of_icase(str, chars, 10), 43);
        EXPECT_EQ(strpy::find_last_not_of_icase(str, chars, 0, 10), 9);
    }
}
