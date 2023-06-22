/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides a function for splitting a string into lines.
 *
 * @example splitlines.cpp
 * Demonstrates the use of the split_lines() function from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <string>
#include <vector>

namespace strpy
{
    /**
     * @brief Splits a string into lines.
     *
     * The input string is split into lines and returned as a vector of strings.
     * The behavior of the split can be controlled using the \p keep_ends parameter.
     *
     * @param str The input string to split.
     * @param keep_ends If \c true, line breaks are included in the resulting lines (optional).
     *
     * @return A vector of strings containing the lines from the input string.
     *
     * @sa https://www.w3schools.com/python/ref_string_splitlines.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::vector<std::string> split_lines(std::string_view str,
                                                                       bool keep_ends = false) noexcept;
}
