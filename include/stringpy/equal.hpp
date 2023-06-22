/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for comparing strings and characters for equality.
 *
 * @example equal.cpp
 * Demonstrates the use of the equal(), equal_icase(), equal_char(),
 * and equal_char_icase() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <type_traits>
#include <cctype>
#include <cstddef>
#include <string>

namespace strpy
{
    /**
     * @brief Compares two strings for equality.
     *
     * Returns \c true if the specified strings are equal, \c false otherwise.
     * The function takes optional arguments to specify the start and end positions for the first string.
     *
     * @param str1 The first string to compare.
     * @param str2 The second string to compare.
     * @param start The start position for the first string (optional).
     * @param end The end position for the first string (optional).
     *
     * @return \c true if the specified strings are equal, \c false otherwise.
     */
    [[nodiscard]] STRINGPY_EXPORT bool equal(std::string_view str1, std::string_view str2, std::size_t start = 0,
                                             std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Compares two strings for equality, ignoring case.
     *
     * Returns \c true if the specified strings are equal, \c false otherwise.
     * The function takes optional arguments to specify the start and end positions for the first string.
     *
     * @param str1 The first string to compare.
     * @param str2 The second string to compare.
     * @param start The start position for the first string (optional).
     * @param end The end position for the first string (optional).
     *
     * @return \c true if the specified strings are equal (ignoring case), \c false otherwise.
     */
    [[nodiscard]] STRINGPY_EXPORT bool equal_icase(std::string_view str1, std::string_view str2, std::size_t start = 0,
                                                   std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Compares two characters for equality.
     *
     * Returns \c true if the specified characters are equal, \c false otherwise.
     * The function is templated to allow for comparison of characters of different types.
     *
     * @tparam Char1 The first type of the character to compare (optional).
     * @tparam Char2 The second type of the character to compare (optional).
     *
     * @param ch1 The first character to compare.
     * @param ch2 The second character to compare.
     *
     * @return \c true if the characters are equal, \c false otherwise.
     */
    template <typename Char1 = std::string::value_type, typename Char2 = Char1>
    [[nodiscard]] constexpr bool equal_char(const Char1 ch1, const Char2 ch2) noexcept
    {
        if constexpr (std::is_signed_v<Char1> == std::is_signed_v<Char2>) {
            return ch1 == ch2;
        }
        else if constexpr (std::is_signed_v<Char1>) {
            return (static_cast<std::make_unsigned_t<Char1>>(ch1) == ch2) && (ch1 >= 0);
        }
        else {
            return (ch1 == static_cast<std::make_unsigned_t<Char2>>(ch2)) && (ch2 >= 0);
        }
    }

    /**
     * @brief Compares two characters for equality, ignoring case.
     *
     * Returns \c true if the specified characters are equal, \c false otherwise.
     * The function is templated to allow for comparison of characters of different types.
     *
     * @tparam Char1 The first type of the character to compare (optional).
     * @tparam Char2 The second type of the character to compare (optional).
     *
     * @param ch1 The first character to compare.
     * @param ch2 The second character to compare.
     *
     * @return \c true if the characters are equal (ignoring case), \c false otherwise.
     */
    template <typename Char1 = std::string::value_type, typename Char2 = Char1>
    [[nodiscard]] bool equal_char_icase(const Char1 ch1, const Char2 ch2) noexcept
    {
        return (equal_char<Char1, Char2>(ch1, ch2)) ||
               (std::toupper(static_cast<unsigned char>(ch1)) == std::toupper(static_cast<unsigned char>(ch2)));
    }
}
