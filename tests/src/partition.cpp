/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/partition.hpp"
#include <gtest/gtest.h>

namespace
{
    TEST(PartitionTest, Basic)
    {
        const std::string str = "I could eat bananas all day";

        auto result = strpy::partition(str, "bananas");
        EXPECT_EQ(std::get<0>(result), "I could eat ");
        EXPECT_EQ(std::get<1>(result), "bananas");
        EXPECT_EQ(std::get<2>(result), " all day");

        result = strpy::partition(str, "apples");
        EXPECT_EQ(std::get<0>(result), str);
        EXPECT_EQ(std::get<1>(result), "");
        EXPECT_EQ(std::get<2>(result), "");
    }

    TEST(PartitionTest, SeparatorNotFound)
    {
        const auto& [first, second, third] = strpy::partition("hello", ",");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "");
    }

    TEST(PartitionTest, SeparatorFound)
    {
        const auto& [first, second, third] = strpy::partition("hello,world", ",");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world");
    }

    TEST(PartitionTest, EmptyString)
    {
        const auto& [first, second, third] = strpy::partition("", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "");
    }

    TEST(PartitionTest, OnlySeparator)
    {
        const auto& [first, second, third] = strpy::partition(",", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "");
    }

    TEST(PartitionTest, MultipleSeparators)
    {
        const auto& [first, second, third] = strpy::partition("hello,world,cpp", ",");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world,cpp");
    }

    TEST(PartitionTest, SeparatorAtStart)
    {
        const auto& [first, second, third] = strpy::partition(",hello,world", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "hello,world");
    }

    TEST(PartitionTest, SeparatorAtEnd)
    {
        const auto& [first, second, third] = strpy::partition("hello,world,", ",");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world,");
    }

    TEST(PartitionTest, LongSeparator)
    {
        const auto& [first, second, third] = strpy::partition("hello||world", "||");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, "||");
        EXPECT_EQ(third, "world");
    }

    TEST(PartitionTest, UnicodeSeparator)
    {
        const auto& [first, second, third] = strpy::partition(u8"hello世界world", u8"世界");
        EXPECT_EQ(first, u8"hello");
        EXPECT_EQ(second, u8"世界");
        EXPECT_EQ(third, u8"world");
    }

    TEST(PartitionICaseTest, SeparatorFound)
    {
        const auto& [first, second, third] = strpy::partition_icase("Hello, World!", ",");
        EXPECT_EQ(first, "Hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, " World!");
    }

    TEST(PartitionICaseTest, SeparatorNotFound)
    {
        const auto& [first, second, third] = strpy::partition_icase("Hello, World!", ".");
        EXPECT_EQ(first, "Hello, World!");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "");
    }

    TEST(PartitionICaseTest, CaseInsensitive)
    {
        const auto& [first, second, third] = strpy::partition_icase("Hello, World!", "WORLD");
        EXPECT_EQ(first, "Hello, ");
        EXPECT_EQ(second, "World");
        EXPECT_EQ(third, "!");
    }

    TEST(PartitionICaseTest, EmptyString)
    {
        const auto& [first, second, third] = strpy::partition_icase("", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "");
    }

    TEST(PartitionICaseTest, EmptySeparator)
    {
        const auto& [first, second, third] = strpy::partition_icase("Hello, World!", "");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "Hello, World!");
    }

    TEST(PartitionICaseTest, SeparatorAtBeginning)
    {
        const auto& [first, second, third] = strpy::partition_icase(",Hello, World!", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "Hello, World!");
    }

    TEST(PartitionICaseTest, SeparatorAtEnd)
    {
        const auto& [first, second, third] = strpy::partition_icase("Hello, World!,", ",");
        EXPECT_EQ(first, "Hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, " World!,");
    }

    TEST(PartitionICaseTest, MultipleSeparators)
    {
        const auto& [first, second, third] = strpy::partition_icase("Hello, World!, How are you?", ",");
        EXPECT_EQ(first, "Hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, " World!, How are you?");
    }

    TEST(PartitionICaseTest, OnlySeparators)
    {
        const auto& [first, second, third] = strpy::partition_icase(",,,,", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, ",,,");
    }

    TEST(RPartitionTest, Basic)
    {
        const std::string str = "I could eat bananas all day, bananas are my favorite fruit";

        auto result = strpy::rpartition(str, "bananas");
        EXPECT_EQ(std::get<0>(result), "I could eat bananas all day, ");
        EXPECT_EQ(std::get<1>(result), "bananas");
        EXPECT_EQ(std::get<2>(result), " are my favorite fruit");

        result = strpy::rpartition(str, "apples");
        EXPECT_EQ(std::get<0>(result), "");
        EXPECT_EQ(std::get<1>(result), "");
        EXPECT_EQ(std::get<2>(result), str);
    }

    TEST(RPartitionTest, SeparatorNotFound)
    {
        const auto& [first, second, third] = strpy::rpartition("hello", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "hello");
    }

    TEST(RPartitionTest, SeparatorFound)
    {
        const auto& [first, second, third] = strpy::rpartition("hello,world", ",");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world");
    }

    TEST(RPartitionTest, EmptyString)
    {
        const auto& [first, second, third] = strpy::rpartition("", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "");
    }

    TEST(RPartitionTest, OnlySeparator)
    {
        const auto& [first, second, third] = strpy::rpartition(",", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "");
    }

    TEST(RPartitionTest, MultipleSeparators)
    {
        const auto& [first, second, third] = strpy::rpartition("hello,world,cpp", ",");
        EXPECT_EQ(first, "hello,world");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "cpp");
    }

    TEST(RPartitionTest, SeparatorAtStart)
    {
        const auto& [first, second, third] = strpy::rpartition(",hello,world", ",");
        EXPECT_EQ(first, ",hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world");
    }

    TEST(RPartitionTest, SeparatorAtEnd)
    {
        const auto& [first, second, third] = strpy::rpartition("hello,world,", ",");
        EXPECT_EQ(first, "hello,world");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "");
    }

    TEST(RPartitionTest, LongSeparator)
    {
        const auto& [first, second, third] = strpy::rpartition("hello||world", "||");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, "||");
        EXPECT_EQ(third, "world");
    }

    TEST(RPartitionTest, UnicodeSeparator)
    {
        const auto& [first, second, third] = strpy::rpartition(u8"hello世界world", u8"世界");
        EXPECT_EQ(first, u8"hello");
        EXPECT_EQ(second, u8"世界");
        EXPECT_EQ(third, u8"world");
    }

    TEST(RPartitionICaseTest, SeparatorNotFound)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("hello", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "hello");
    }

    TEST(RPartitionICaseTest, SeparatorFound)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("hello,world", ",");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world");
    }

    TEST(RPartitionICaseTest, EmptyString)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, "");
        EXPECT_EQ(third, "");
    }

    TEST(RPartitionICaseTest, OnlySeparator)
    {
        const auto& [first, second, third] = strpy::rpartition_icase(",", ",");
        EXPECT_EQ(first, "");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "");
    }

    TEST(RPartitionICaseTest, MultipleSeparators)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("hello,world,cpp", ",");
        EXPECT_EQ(first, "hello,world");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "cpp");
    }

    TEST(RPartitionICaseTest, CaseInsensitiveSeparator)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("HELLO,WORLD,CPP", ",w");
        EXPECT_EQ(first, "HELLO");
        EXPECT_EQ(second, ",W");
        EXPECT_EQ(third, "ORLD,CPP");
    }

    TEST(RPartitionICaseTest, SeparatorAtStart)
    {
        const auto& [first, second, third] = strpy::rpartition_icase(",hello,world", ",");
        EXPECT_EQ(first, ",hello");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "world");
    }

    TEST(RPartitionICaseTest, SeparatorAtEnd)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("hello,world,", ",");
        EXPECT_EQ(first, "hello,world");
        EXPECT_EQ(second, ",");
        EXPECT_EQ(third, "");
    }

    TEST(RPartitionICaseTest, LongSeparator)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("hello||world", "||");
        EXPECT_EQ(first, "hello");
        EXPECT_EQ(second, "||");
        EXPECT_EQ(third, "world");
    }

    TEST(RPartitionICaseTest, UnicodeSeparator)
    {
        const auto& [first, second, third] = strpy::rpartition_icase(u8"hello世界world", u8"世界");
        EXPECT_EQ(first, u8"hello");
        EXPECT_EQ(second, u8"世界");
        EXPECT_EQ(third, u8"world");
    }

    TEST(RPartitionICaseTest, CaseInsensitiveLongSeparator)
    {
        const auto& [first, second, third] = strpy::rpartition_icase("HELLO||WORLD", "||w");
        EXPECT_EQ(first, "HELLO");
        EXPECT_EQ(second, "||W");
        EXPECT_EQ(third, "ORLD");
    }
}
