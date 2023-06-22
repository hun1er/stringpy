/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/join.hpp"
#include <gtest/gtest.h>
#include <list>
#include <vector>

namespace
{
    struct Point
    {
        int x{};
        int y{};

        friend std::ostream& operator<<(std::ostream& os, const Point& p)
        {
            os << "(" << p.x << ", " << p.y << ")";
            return os;
        }
    };

    TEST(JoinTest, EmptyContainer)
    {
        const std::vector<std::string> strings{};
        const std::string delimiter = ", ";
        EXPECT_EQ(strpy::join(strings, delimiter), "");
    }

    TEST(JoinTest, SingleElement)
    {
        const std::vector<std::string> strings = {"one"};
        const std::string delimiter = ", ";
        EXPECT_EQ(strpy::join(strings, delimiter), "one");
    }

    TEST(JoinTest, MultipleElements)
    {
        const std::vector<std::string> strings = {"one", "two", "three"};
        const std::string delimiter = ", ";
        EXPECT_EQ(strpy::join(strings, delimiter), "one, two, three");
    }

    TEST(JoinTest, DifferentContainerType)
    {
        const std::list<int> numbers = {1, 2, 3};
        const std::string delimiter = " + ";
        EXPECT_EQ(strpy::join(numbers, delimiter), "1 + 2 + 3");
    }

    TEST(JoinTest, DifferentDelimiter)
    {
        const std::vector<std::string> strings = {"one", "two", "three"};
        const std::string delimiter = "-";
        EXPECT_EQ(strpy::join(strings, delimiter), "one-two-three");
    }

    TEST(JoinTest, DifferentValueTypes)
    {
        const std::vector<int> numbers = {1, 2, 3};
        std::string delimiter = ", ";
        EXPECT_EQ(strpy::join(numbers, delimiter), "1, 2, 3");

        const std::vector<double> doubles = {1.1, 2.2, 3.3};
        delimiter = " - ";
        EXPECT_EQ(strpy::join(doubles, delimiter), "1.1 - 2.2 - 3.3");
    }

    TEST(JoinTest, CustomType)
    {
        const std::vector<Point> points = {
          {1, 2},
          {3, 4},
          {5, 6}
        };

        const std::string delimiter = " : ";
        EXPECT_EQ(strpy::join(points, delimiter), "(1, 2) : (3, 4) : (5, 6)");
    }

    TEST(JoinTest, EmptyDelimiter)
    {
        const std::vector<std::string> strings = {"one", "two", "three"};
        const std::string delimiter{};
        EXPECT_EQ(strpy::join(strings, delimiter), "onetwothree");
    }
}
