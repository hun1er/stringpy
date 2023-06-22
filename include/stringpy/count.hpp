/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for counting the occurrences of a substring within a string.
 *
 * @example count.cpp
 * Demonstrates the use of the count() and count_icase() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>

namespace strpy
{
    /**
     * @brief Counts the number of non-overlapping occurrences of a substring within a string.
     *
     * Returns the number of non-overlapping occurrences of the substring within the string,
     * starting at position \p start and ending at position \p end.
     *
     * @param str The string to search within.
     * @param sub The substring to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The number of non-overlapping occurrences of the substring.
     *
     * @sa https://www.w3schools.com/python/ref_string_count.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t count(std::string_view str, std::string_view sub, std::size_t start = 0,
                                                    std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Counts the number of non-overlapping occurrences of a substring within a string, ignoring case.
     *
     * Returns the number of non-overlapping occurrences of the substring within the string,
     * starting at position \p start and ending at position \p end.
     *
     * @param str The string to search within.
     * @param sub The substring to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The number of non-overlapping occurrences of the substring.
     *
     * @sa https://www.w3schools.com/python/ref_string_count.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t count_icase(std::string_view str, std::string_view sub,
                                                          std::size_t start = 0,
                                                          std::size_t end = std::string_view::npos) noexcept;
}
