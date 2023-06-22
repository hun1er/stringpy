/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for justifying strings to a given minimum width.
 *
 * @example just.cpp
 * Demonstrates the use of the ljust(), rjust(), and zfill() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/const.hpp"
#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>
#include <string>

namespace strpy
{
    /**
     * @brief Returns a left-justified string of a given minimum width.
     *
     * The fill character is appended to the right of the input string
     * until the resulting string reaches the minimum width.
     * If the size of \p str is greater than or equal to \p length, a copy of \p str is returned.
     *
     * @param str The input string to justify.
     * @param length The minimum width of the resulting string.
     * @param fill_char The character used to fill the resulting string (optional).
     *
     * @return A left-justified string of minimum width \p length.
     *
     * @sa https://www.w3schools.com/python/ref_string_ljust.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string ljust(std::string_view str, std::size_t length,
                                                    std::string::value_type fill_char = SPACE) noexcept;

    /**
     * @brief Returns a right-justified string of a given minimum width.
     *
     * The fill character is prepended to the left of the input string
     * until the resulting string reaches the minimum width.
     * If the size of \p str is greater than or equal to \p length, a copy of \p str is returned.
     *
     * @param str The input string to justify.
     * @param length The minimum width of the resulting string.
     * @param fill_char The character used to fill the resulting string (optional).
     *
     * @return A right-justified string of minimum width \p length.
     *
     * @sa https://www.w3schools.com/python/ref_string_rjust.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string rjust(std::string_view str, std::size_t length,
                                                    std::string::value_type fill_char = SPACE) noexcept;

    /**
     * @brief Returns a zero-filled string of a given minimum width.
     *
     * The character <tt>'0'</tt> is prepended to the left of the input string
     * until the resulting string reaches the minimum width.
     * If the size of \p str is greater than or equal to \p length, a copy of \p str is returned.
     *
     * @param str The input string to fill with zeros.
     * @param length The minimum width of the resulting string.
     *
     * @return A zero-filled string of minimum width \p length.
     *
     * @sa https://www.w3schools.com/python/ref_string_zfill.asp
     */
    [[nodiscard]] inline std::string zfill(const std::string_view str, const std::size_t length) noexcept
    {
        return rjust(str, length, '0');
    }
}
