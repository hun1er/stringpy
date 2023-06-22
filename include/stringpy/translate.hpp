/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for translating characters in a string using a translation table.
 *
 * @example translate.cpp
 * Demonstrates the use of the make_trans() and translate() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/const.hpp"
#include "stringpy/export.hpp"
#include <string_view>
#include <unordered_map>
#include <string>

namespace strpy
{
    /**
     * @brief Type alias for the translation table used by the \ref strpy::make_trans
     * and \ref strpy::translate functions.
     *
     * It is an unordered_map where the key is the character to be replaced or deleted,
     * and the value is the character to replace it with or a special value indicating
     * that the character should be deleted.
     */
    using TransMap = std::unordered_map<std::string::value_type, std::string::value_type>;

    /**
     * @brief Creates a translation table for use with the \ref strpy::translate function.
     *
     * The first two arguments, \p from and \p to, are used to create the character replacement map.
     * The third argument, \p delete_chars, is an optional argument
     * that specifies characters to be deleted from the string.
     *
     * @param from A string of characters to be replaced.
     * @param to A string of characters to replace the characters in \p from.
     * @param delete_chars String of characters to be deleted from the string (optional).
     *
     * @return An unordered_map representing the translation table.
     *
     * @sa https://www.w3schools.com/python/ref_string_maketrans.asp
     */
    [[nodiscard]] STRINGPY_EXPORT TransMap make_trans(std::string_view from, std::string_view to,
                                                      std::string_view delete_chars) noexcept;

    /**
     * @brief Creates a translation table for use with the \ref strpy::translate function.
     *
     * This is an overloaded function. It is equivalent to calling <tt>make_trans(from, to, "")</tt>.
     *
     * @param from A string of characters to be replaced.
     * @param to A string of characters to replace the characters in \p from.
     *
     * @return An unordered_map representing the translation table.
     *
     * @sa https://www.w3schools.com/python/ref_string_maketrans.asp
     */
    [[nodiscard]] TransMap inline make_trans(const std::string_view from, const std::string_view to) noexcept
    {
        return make_trans(from, to, EMPTY_STR);
    }

    /**
     * @brief Translates characters in a string using a translation table.
     *
     * Returns a string where all characters have been translated using the
     * translation table \p trans_map.
     * The translation table is created using the \ref strpy::make_trans function.
     *
     * @param str The string to translate.
     * @param trans_map The translation table to use for character replacement.
     *
     * @return A new string where all characters in str have been translated using the translation table.
     *
     * @sa https://www.w3schools.com/python/ref_string_translate.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string translate(std::string_view str, const TransMap& trans_map) noexcept;
}
