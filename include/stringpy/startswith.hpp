/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for checking if a string starts with a specified prefix.
 *
 * @example startswith.cpp
 * Demonstrates the use of the starts_with() and starts_with_icase() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>

namespace strpy
{
    /**
     * @brief Checks if a string starts with the specified prefix.
     *
     * Returns \c true if the string starts with the specified prefix, \c false otherwise.
     * The optional arguments \p start and \p end can be used to specify a range of characters to consider.
     * If \p start is specified, only characters from position \p start and onwards are considered.
     * If \p end is specified, only characters up to position \p end are considered.
     *
     * @param str The string to check.
     * @param prefix The prefix to look for.
     * @param start The starting position of the range of characters to consider (optional).
     * @param end The ending position of the range of characters to consider (optional).
     *
     * @return \c true if \p str starts with \p prefix, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_startswith.asp
     */
    [[nodiscard]] STRINGPY_EXPORT bool starts_with(std::string_view str, std::string_view prefix, std::size_t start = 0,
                                                   std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Checks if a string starts with the specified prefix, ignoring case.
     *
     * Returns \c true if the string starts with the specified prefix, \c false otherwise.
     * The optional arguments \p start and \p end can be used to specify a range of characters to consider.
     * If \p start is specified, only characters from position \p start and onwards are considered.
     * If \p end is specified, only characters up to position \p end are considered.
     *
     * @param str The string to check.
     * @param prefix The prefix to look for.
     * @param start The starting position of the range of characters to consider (optional).
     * @param end The ending position of the range of characters to consider (optional).
     *
     * @return \c true if \p str starts with \p prefix (ignoring case), \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_startswith.asp
     */
    [[nodiscard]] STRINGPY_EXPORT bool starts_with_icase(std::string_view str, std::string_view prefix,
                                                         std::size_t start = 0,
                                                         std::size_t end = std::string_view::npos) noexcept;
}
