/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for checking if a string ends with a specified suffix.
 *
 * @example endswith.cpp
 * Demonstrates the use of the ends_with() and ends_with_icase() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>

namespace strpy
{
    /**
     * @brief Checks if a string ends with the specified suffix.
     *
     * Returns \c true if the string ends with the specified suffix, \c false otherwise.
     * The optional arguments \p start and \p end can be used to specify a range of characters to consider.
     * If \p start is specified, only characters from position \p start and onwards are considered.
     * If \p end is specified, only characters up to position \p end are considered.
     *
     * @param str The string to check.
     * @param suffix The suffix to look for.
     * @param start The starting position of the range of characters to consider (optional).
     * @param end The ending position of the range of characters to consider (optional).
     *
     * @return \c true if \p str ends with \p suffix, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_endswith.asp
     */
    [[nodiscard]] STRINGPY_EXPORT bool ends_with(std::string_view str, std::string_view suffix, std::size_t start = 0,
                                                 std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Checks if a string ends with the specified suffix, ignoring case.
     *
     * Returns \c true if the string ends with the specified suffix, \c false otherwise.
     * The optional arguments \p start and \p end can be used to specify a range of characters to consider.
     * If \p start is specified, only characters from position \p start and onwards are considered.
     * If \p end is specified, only characters up to position \p end are considered.
     *
     * @param str The string to check.
     * @param suffix The suffix to look for.
     * @param start The starting position of the range of characters to consider (optional).
     * @param end The ending position of the range of characters to consider (optional).
     *
     * @return \c true if \p str ends with \p suffix (ignoring case), \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_endswith.asp
     */
    [[nodiscard]] STRINGPY_EXPORT bool ends_with_icase(std::string_view str, std::string_view suffix,
                                                       std::size_t start = 0,
                                                       std::size_t end = std::string_view::npos) noexcept;
}
