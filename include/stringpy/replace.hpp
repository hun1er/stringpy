/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for replacing substrings within a string.
 *
 * @example replace.cpp
 * Demonstrates the use of the replace() and replace_icase() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>
#include <string>

namespace strpy
{
    /**
     * @brief Replaces all occurrences of a substring within a string with another substring.
     *
     * All occurrences of a substring within the input string are replaced with another substring.
     * An optional argument \p count can be used to specify the maximum number of replacements to perform.
     * If count is equal to \c std::string::npos, all occurrences are replaced.
     *
     * @param str The input string to perform the replacement on.
     * @param old_value The substring to search for within the input string.
     * @param new_value The substring to replace all occurrences of \p old_value with.
     * @param count The maximum number of replacements to perform (optional).
     *
     * @return A new string with the specified replacements made.
     *
     * @sa https://www.w3schools.com/python/ref_string_replace.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string replace(std::string_view str, std::string_view old_value,
                                                      std::string_view new_value,
                                                      std::size_t count = std::string::npos) noexcept;

    /**
     * @brief Replaces all occurrences of a substring within a string with another substring, ignoring case.
     *
     * All occurrences of a substring within the input string are replaced with another substring.
     * An optional argument \p count can be used to specify the maximum number of replacements to perform.
     * If count is equal to \c std::string::npos, all occurrences are replaced.
     *
     * @param str The input string to perform the replacement on.
     * @param old_value The substring to search for within the input string.
     * @param new_value The substring to replace all occurrences of \p old_value with.
     * @param count The maximum number of replacements to perform (optional).
     *
     * @return A new string with the specified replacements made.
     *
     * @sa https://www.w3schools.com/python/ref_string_replace.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string replace_icase(std::string_view str, std::string_view old_value,
                                                            std::string_view new_value,
                                                            std::size_t count = std::string::npos) noexcept;
}
