/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/partition.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"apple:banana:cherry"};
        const auto& [before, sep, after] = strpy::partition(str, ":");

        std::cout << "String: " << str << '\n';
        std::cout << "Delimiter: \":\"" << '\n';
        std::cout << "Before: \"" << before << '\"' << '\n';
        std::cout << "Separator: \"" << sep << '\"' << '\n';
        std::cout << "After: \"" << after << '\"' << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"apple:banana:cherry"};
        const auto& [before, sep, after] = strpy::partition_icase(str, "BANANA");

        std::cout << "String: " << str << '\n';
        std::cout << "Delimiter: \"BANANA\"" << '\n';
        std::cout << "Before: \"" << before << '\"' << '\n';
        std::cout << "Separator: \"" << sep << '\"' << '\n';
        std::cout << "After: \"" << after << '\"' << '\n';
    }

    void example3()
    {
        constexpr std::string_view str{"apple:banana:cherry"};
        const auto& [before, sep, after] = strpy::rpartition(str, ":");

        std::cout << "String: " << str << '\n';
        std::cout << "Delimiter: \":\"" << '\n';
        std::cout << "Before: \"" << before << '\"' << '\n';
        std::cout << "Separator: \"" << sep << '\"' << '\n';
        std::cout << "After: \"" << after << '\"' << '\n';
    }

    void example4()
    {
        constexpr std::string_view str{"apple:banana:cherry"};
        const auto& [before, sep, after] = strpy::rpartition_icase(str, "CHERRY");

        std::cout << "String: " << str << '\n';
        std::cout << "Delimiter: \"CHERRY\"" << '\n';
        std::cout << "Before: \"" << before << '\"' << '\n';
        std::cout << "Separator: \"" << sep << '\"' << '\n';
        std::cout << "After: \"" << after << '\"' << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (partition)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (partition_icase)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (rpartition)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (rpartition_icase)" << '\n';
    example4();
}

// Program output:
//
// String: apple:banana:cherry
// Delimiter: ":"
// Before: "apple"
// Separator: ":"
// After: "banana:cherry"
//
// Example 2 (partition_icase)
// String: apple:banana:cherry
// Delimiter: "BANANA"
// Before: "apple:"
// Separator: "banana"
// After: ":cherry"
//
// Example 3 (rpartition)
// String: apple:banana:cherry
// Delimiter: ":"
// Before: "apple:banana"
// Separator: ":"
// After: "cherry"
//
// Example 4 (rpartition_icase)
// String: apple:banana:cherry
// Delimiter: "CHERRY"
// Before: "apple:banana:"
// Separator: "cherry"
// After: ""
