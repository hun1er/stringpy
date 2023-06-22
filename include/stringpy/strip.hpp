/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for removing leading and trailing characters from a string.
 *
 * @example strip.cpp
 * Demonstrates the use of the lstrip(), rstrip(), and strip() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/const.hpp"
#include <string_view>
#include <string>

namespace strpy
{
    /**
     * @brief Removes leading characters from a string.
     *
     * Returns a new string with leading characters removed from the input string.
     * The characters to be removed are specified in the \p chars parameter.
     * If \p chars is not provided, the function removes leading whitespace characters by default.
     *
     * @tparam Ret The type of the returned value. Must be either \c std::string or \c std::string_view.
     *
     * @param str The string to remove leading characters from.
     * @param chars The characters to remove (optional).
     *
     * @return A new string with the leading characters removed.
     *
     * @sa https://www.w3schools.com/python/ref_string_lstrip.asp
     */
    template <typename Ret = std::string>
    [[nodiscard]] Ret lstrip(const std::string_view str, const std::string_view chars = SPACE_CHARS) noexcept
    {
        static_assert(std::is_same_v<Ret, std::string> || std::is_same_v<Ret, std::string_view>,
                      "Return type must be either std::string or std::string_view");

        const auto pos = str.find_first_not_of(chars);

        if (std::string_view::npos == pos) {
            return {};
        }

        if constexpr (std::is_same_v<Ret, std::string>) {
            return std::string{str.substr(pos, str.length() - pos)};
        }
        else {
            return str.substr(pos, str.length() - pos);
        }
    }

    /**
     * @brief Removes leading occurrences of a character from a string.
     *
     * Returns a new string with leading occurrences of the character removed from the input string.
     *
     * @tparam Ret The type of the returned value. Must be either \c std::string or \c std::string_view.
     *
     * @param str The string to remove leading characters from.
     * @param ch The character to remove.
     *
     * @return A new string with the leading occurrences of \p ch removed.
     *
     * @sa https://www.w3schools.com/python/ref_string_lstrip.asp
     */
    template <typename Ret = std::string>
    [[nodiscard]] Ret lstrip(const std::string_view str, const std::string::value_type ch) noexcept
    {
        return lstrip<Ret>(str, {&ch, 1});
    }

    /**
     * @brief Removes trailing characters from a string.
     *
     * Returns a new string with trailing characters removed from the input string.
     * The characters to be removed are specified in the \p chars parameter.
     * If \p chars is not provided, the function removes trailing whitespace characters by default.
     *
     * @tparam Ret The type of the returned value. Must be either \c std::string or \c std::string_view.
     *
     * @param str The string to remove trailing characters from.
     * @param chars The characters to remove (optional).
     *
     * @return A new string with the trailing characters removed.
     *
     * @sa https://www.w3schools.com/python/ref_string_rstrip.asp
     */
    template <typename Ret = std::string>
    [[nodiscard]] Ret rstrip(const std::string_view str, const std::string_view chars = SPACE_CHARS) noexcept
    {
        static_assert(std::is_same_v<Ret, std::string> || std::is_same_v<Ret, std::string_view>,
                      "Return type must be either std::string or std::string_view");

        const auto pos = str.find_last_not_of(chars);

        if (std::string_view::npos == pos) {
            return {};
        }

        if constexpr (std::is_same_v<Ret, std::string>) {
            return std::string{str.substr(0, pos + 1)};
        }
        else {
            return str.substr(0, pos + 1);
        }
    }

    /**
     * @brief Removes trailing occurrences of a character from a string.
     *
     * Returns a new string with trailing occurrences of the character removed from the input string.
     *
     * @tparam Ret The type of the returned value. Must be either \c std::string or \c std::string_view.
     *
     * @param str The string to remove trailing characters from.
     * @param ch The character to remove.
     *
     * @return A new string with the trailing occurrences of \p ch removed.
     *
     * @sa https://www.w3schools.com/python/ref_string_rstrip.asp
     */
    template <typename Ret = std::string>
    [[nodiscard]] Ret rstrip(const std::string_view str, const std::string::value_type ch) noexcept
    {
        return rstrip<Ret>(str, {&ch, 1});
    }

    /**
     * @brief Removes leading and trailing occurrences of a character from a string.
     *
     * Returns a new string with leading and trailing occurrences of the character removed from the input string.
     *
     * @tparam Ret The type of the returned value. Must be either \c std::string or \c std::string_view.
     *
     * @param str The string to remove leading and trailing characters from.
     * @param ch The character to remove.
     *
     * @return A new string with the leading and trailing occurrences of \p ch removed.
     *
     * @sa https://www.w3schools.com/python/ref_string_strip.asp
     */
    template <typename Ret = std::string>
    [[nodiscard]] Ret strip(const std::string_view str, const std::string::value_type ch) noexcept
    {
        return rstrip<Ret>(lstrip<std::string_view>(str, ch), ch);
    }

    /**
     * @brief Removes leading and trailing characters from a string.
     *
     * Returns a new string with leading and trailing characters removed from the input string.
     * The characters to be removed are specified in the \p chars parameter.
     * If \p chars is not provided, the function removes leading and trailing whitespace characters by default.
     *
     * @tparam Ret The type of the returned value. Must be either \c std::string or \c std::string_view.
     *
     * @param str The string to remove leading and trailing characters from.
     * @param chars The characters to remove (optional).
     *
     * @return A new string with the leading and trailing characters removed.
     *
     * @sa https://www.w3schools.com/python/ref_string_strip.asp
     */
    template <typename Ret = std::string>
    [[nodiscard]] Ret strip(const std::string_view str, const std::string_view chars = SPACE_CHARS) noexcept
    {
        return rstrip<Ret>(lstrip<std::string_view>(str, chars), chars);
    }
}
