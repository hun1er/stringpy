/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/equal.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(EqualTest, Basic)
    {
        constexpr std::string_view str1{"The quick brown fox jumps over the lazy dog"};
        constexpr std::string_view str2{"The quick red fox jumps over the lazy dog"};

        EXPECT_TRUE(strpy::equal("test", "test"));
        EXPECT_FALSE(strpy::equal("test", "Test"));
        EXPECT_TRUE(strpy::equal(str1, str1));
        EXPECT_FALSE(strpy::equal(str1, str2));
        EXPECT_TRUE(strpy::equal(str1, "The quick", 0, 9));
        EXPECT_FALSE(strpy::equal(str1, "The quick red", 0, 13));
        EXPECT_TRUE(strpy::equal(str1, "fox jumps over the lazy dog", 16));
    }

    TEST(EqualTest, EmptyStrings)
    {
        EXPECT_TRUE(strpy::equal("", ""));
        EXPECT_FALSE(strpy::equal("", "test"));
    }

    TEST(EqualTest, OptionalArguments)
    {
        EXPECT_TRUE(strpy::equal("test", "test", 0, 4));
        EXPECT_FALSE(strpy::equal("test", "test", 1, 3));
        EXPECT_FALSE(strpy::equal("test", "Test", 0, 4));
    }

    TEST(EqualTest, InvalidArguments)
    {
        EXPECT_FALSE(strpy::equal("test", "test", 5));
        EXPECT_FALSE(strpy::equal("test", "test", 0, std::string::npos + 1));
        EXPECT_FALSE(strpy::equal("test", "test", 3, 2));
        EXPECT_FALSE(strpy::equal("test", "test", std::string::npos));
    }

    TEST(EqualTest, DifferentLengths)
    {
        EXPECT_FALSE(strpy::equal("test", "testing"));
        EXPECT_FALSE(strpy::equal("testing", "test"));
    }

    TEST(EqualTest, Substrings)
    {
        EXPECT_TRUE(strpy::equal("testing", "test", 0, 4));
        EXPECT_FALSE(strpy::equal("testing", "test", 1, 5));
    }

    TEST(EqualTest, CaseSensitivity)
    {
        EXPECT_FALSE(strpy::equal("test", "Test"));
        EXPECT_FALSE(strpy::equal("Test", "test"));
    }

    TEST(EqualTest, SpecialCharacters)
    {
        EXPECT_TRUE(strpy::equal("!@#$%^&*()", "!@#$%^&*()"));
        EXPECT_FALSE(strpy::equal("!@#$%^&*()", "!@#$%^&*()_"));
    }

    TEST(EqualTest, MixedCharacters)
    {
        EXPECT_TRUE(strpy::equal("test123!@#", "test123!@#"));
        EXPECT_FALSE(strpy::equal("test123!@#", "Test123!@#"));
    }

    TEST(EqualTest, UnicodeCharacters)
    {
        EXPECT_TRUE(strpy::equal(u8"Привет", u8"Привет"));
        EXPECT_FALSE(strpy::equal(u8"Привет", u8"привет"));
    }

    TEST(EqualICaseTest, Basic)
    {
        constexpr std::string_view str1{"thE quiCk bRoWn fOX jumPs oVeR the lAZY DoG"};
        constexpr std::string_view str2{"tHe QUIcK reD fox JuMpS oVeR the laZY doG"};

        EXPECT_TRUE(strpy::equal_icase("TeST", "tEst"));
        EXPECT_TRUE(strpy::equal_icase(str1, str1));
        EXPECT_FALSE(strpy::equal_icase(str1, str2));
        EXPECT_TRUE(strpy::equal_icase(str1, "ThE Quick", 0, 9));
        EXPECT_FALSE(strpy::equal_icase(str1, "THe QUICk rEd", 0, 13));
        EXPECT_TRUE(strpy::equal_icase(str1, "FoX JUmps oVeR tHE lAzy Dog", 16));
    }

    TEST(EqualICaseTest, EmptyStrings)
    {
        EXPECT_TRUE(strpy::equal_icase("", ""));
        EXPECT_FALSE(strpy::equal_icase("", "test"));
    }

    TEST(EqualICaseTest, OptionalArguments)
    {
        EXPECT_TRUE(strpy::equal_icase("tesT", "TesT", 0, 4));
        EXPECT_FALSE(strpy::equal_icase("tEst", "teSt", 1, 3));
    }

    TEST(EqualICaseTest, InvalidArguments)
    {
        EXPECT_FALSE(strpy::equal_icase("teSt", "TEST", 5));
        EXPECT_FALSE(strpy::equal_icase("TEST", "TESt", 0, std::string::npos + 1));
        EXPECT_FALSE(strpy::equal_icase("tESt", "tEST", 3, 2));
        EXPECT_FALSE(strpy::equal_icase("TeSt", "test", std::string::npos));
    }

    TEST(EqualICaseTest, DifferentLengths)
    {
        EXPECT_FALSE(strpy::equal_icase("TesT", "TeSTing"));
        EXPECT_FALSE(strpy::equal_icase("tEsTiNG", "TesT"));
    }

    TEST(EqualICaseTest, Substrings)
    {
        EXPECT_TRUE(strpy::equal_icase("tEsting", "tesT", 0, 4));
        EXPECT_FALSE(strpy::equal_icase("TeSTinG", "TEST", 1, 5));
    }

    TEST(EqualICaseTest, SpecialCharacters)
    {
        EXPECT_TRUE(strpy::equal_icase("!@#$%^&*()", "!@#$%^&*()"));
        EXPECT_FALSE(strpy::equal_icase("!@#$%^&*()", "!@#$%^&*()_"));
    }

    TEST(EqualICaseTest, MixedCharacters)
    {
        EXPECT_TRUE(strpy::equal_icase("TEst123!@#", "tEST123!@#"));
    }

    TEST(EqualCharTest, Basic)
    {
        EXPECT_TRUE(strpy::equal_char('a', 'a'));
        EXPECT_TRUE(strpy::equal_char('A', 'A'));
        EXPECT_FALSE(strpy::equal_char('a', 'A'));
        EXPECT_FALSE(strpy::equal_char('A', 'a'));
        EXPECT_FALSE(strpy::equal_char('a', 'b'));
        EXPECT_FALSE(strpy::equal_char('A', 'B'));
        EXPECT_FALSE(strpy::equal_char('a', 'Z'));
        EXPECT_FALSE(strpy::equal_char('A', 'z'));
        EXPECT_FALSE(strpy::equal_char('1', 'a'));
        EXPECT_FALSE(strpy::equal_char('1', 'A'));
        EXPECT_TRUE(strpy::equal_char('a', L'a'));
        EXPECT_FALSE(strpy::equal_char('a', L'b'));
        EXPECT_TRUE(strpy::equal_char(97, 97));
        EXPECT_FALSE(strpy::equal_char(97, 98));
        EXPECT_TRUE(strpy::equal_char(97, static_cast<long long>(97)));
        EXPECT_FALSE(strpy::equal_char(97, static_cast<long long>(98)));
    }

    TEST(EqualCharTest, ControlAndSpecialCharacters)
    {
        EXPECT_TRUE(strpy::equal_char('\n', '\n'));
        EXPECT_TRUE(strpy::equal_char('\t', '\t'));
        EXPECT_TRUE(strpy::equal_char(' ', ' '));
        EXPECT_TRUE(strpy::equal_char('!', '!'));
        EXPECT_TRUE(strpy::equal_char('@', '@'));
        EXPECT_TRUE(strpy::equal_char('#', '#'));
        EXPECT_TRUE(strpy::equal_char('$', '$'));
        EXPECT_TRUE(strpy::equal_char('%', '%'));
        EXPECT_TRUE(strpy::equal_char('^', '^'));
        EXPECT_TRUE(strpy::equal_char('&', '&'));
    }

    TEST(EqualCharICaseTest, Basic)
    {
        EXPECT_TRUE(strpy::equal_char_icase('a', 'a'));
        EXPECT_TRUE(strpy::equal_char_icase('A', 'A'));
        EXPECT_TRUE(strpy::equal_char_icase('a', 'A'));
        EXPECT_TRUE(strpy::equal_char_icase('A', 'a'));
        EXPECT_FALSE(strpy::equal_char_icase('a', 'b'));
        EXPECT_FALSE(strpy::equal_char_icase('A', 'B'));
        EXPECT_TRUE(strpy::equal_char_icase('z', 'Z'));
        EXPECT_TRUE(strpy::equal_char_icase('Z', 'z'));
        EXPECT_FALSE(strpy::equal_char_icase('a', 'Z'));
        EXPECT_FALSE(strpy::equal_char_icase('A', 'z'));
        EXPECT_FALSE(strpy::equal_char_icase('1', 'a'));
        EXPECT_FALSE(strpy::equal_char_icase('1', 'A'));
        EXPECT_TRUE(strpy::equal_char_icase('a', L'A'));
        EXPECT_FALSE(strpy::equal_char_icase('a', L'B'));
        EXPECT_TRUE(strpy::equal_char_icase(97, 65));
        EXPECT_FALSE(strpy::equal_char_icase(97, 66));
        EXPECT_TRUE(strpy::equal_char_icase(97, static_cast<long long>(65)));
        EXPECT_FALSE(strpy::equal_char_icase(97, static_cast<long long>(66)));
    }

    TEST(EqualCharICaseTest, ControlAndSpecialCharacters)
    {
        EXPECT_TRUE(strpy::equal_char_icase('\n', '\n'));
        EXPECT_TRUE(strpy::equal_char_icase('\t', '\t'));
        EXPECT_TRUE(strpy::equal_char_icase(' ', ' '));
        EXPECT_TRUE(strpy::equal_char_icase('!', '!'));
        EXPECT_TRUE(strpy::equal_char_icase('@', '@'));
        EXPECT_TRUE(strpy::equal_char_icase('#', '#'));
        EXPECT_TRUE(strpy::equal_char_icase('$', '$'));
        EXPECT_TRUE(strpy::equal_char_icase('%', '%'));
        EXPECT_TRUE(strpy::equal_char_icase('^', '^'));
        EXPECT_TRUE(strpy::equal_char_icase('&', '&'));
    }
}
