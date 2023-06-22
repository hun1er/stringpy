/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for splitting strings.
 *
 * @example split.cpp
 * Demonstrates the use of the split(), rsplit(), and split() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <type_traits>
#include <cstddef>
#include <string>
#include <vector>

namespace strpy
{
    /**
     * @brief Specifies options for splitting strings.
     */
    enum class StringSplitOptions : unsigned
    {
        /** @brief Indicates that no options should be used when splitting strings. */
        none = 0U,

        /** @brief Indicates that entries should be trimmed when splitting strings. */
        trim = 1U << 0U,

        /** @brief Indicates that empty entries should be removed when splitting strings. */
        remove_empty = 1U << 1U,

        /**
         * @brief Indicates that empty entries should be removed and entries should be trimmed when splitting strings.
         */
        trim_remove_empty = trim | remove_empty
    };

    /**
     * @brief Splits a string into substrings using any space character as delimiter.
     *
     * The input string is split into substrings using any space character as delimiter.
     * The substrings are returned as a vector of strings.
     * An optional argument \p max_split can be used to specify the maximum number of splits to perform.
     * If \p max_split is equal to \c std::string::npos, all possible splits are performed.
     *
     * @param str The input string to split.
     * @param max_split The maximum number of splits to perform (optional).
     *
     * @return A vector of strings containing the substrings.
     *
     * @sa https://www.w3schools.com/python/ref_string_split.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::vector<std::string> split(std::string_view str,
                                                                 std::size_t max_split = std::string::npos) noexcept;

    /**
     * @brief Splits a string into substrings using a specified delimiter.
     *
     * The input string is split into substrings using the specified delimiter.
     * The substrings are returned as a vector of strings.
     * An optional argument \p max_split can be used to specify the maximum number of splits to perform.
     * If \p max_split is equal to \c std::string::npos, all possible splits are performed.
     * The behavior of the split can be controlled using the \p options parameter.
     *
     * @param str The input string to split.
     * @param delimiter The delimiter used to split the string.
     * @param max_split The maximum number of splits to perform (optional).
     * @param options A bitwise combination of StringSplitOptions values that specifies
     * options for splitting strings (optional).
     *
     * @return A vector of strings containing the substrings.
     *
     * @sa https://www.w3schools.com/python/ref_string_split.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::vector<std::string>
      split(std::string_view str, std::string_view delimiter, std::size_t max_split = std::string::npos,
            StringSplitOptions options = StringSplitOptions::none) noexcept;

    /**
     * @brief Splits a string into substrings using a specified delimiter.
     *
     * The input string is split into substrings using the specified delimiter.
     * The substrings are returned as a vector of strings.
     * The behavior of the split can be controlled using the \p options parameter.
     *
     * @param str The input string to split.
     * @param delimiter The delimiter used to split the string.
     * @param options A bitwise combination of StringSplitOptions values that specifies options for splitting strings.
     *
     * @return A vector of strings containing the substrings.
     *
     * @sa https://www.w3schools.com/python/ref_string_split.asp
     */
    [[nodiscard]] inline std::vector<std::string> split(const std::string_view str, const std::string_view delimiter,
                                                        const StringSplitOptions options) noexcept
    {
        return split(str, delimiter, std::string::npos, options);
    }

    /**
     * @brief Splits a string into substrings using any space character as delimiter,
     * starting from the end of the string.
     *
     * The input string is split into substrings using any space character as delimiter.
     * The substrings are returned as a vector of strings.
     * An optional argument \p max_split can be used to specify the maximum number of splits to perform.
     * If \p max_split is equal to \c std::string::npos, all possible splits are performed.
     * The splitting starts from the end of the string and proceeds towards the beginning.
     *
     * @param str The input string to split.
     * @param max_split The maximum number of splits to perform (optional).
     *
     * @return A vector of strings containing the substrings in reverse order.
     *
     * @sa https://www.w3schools.com/python/ref_string_rsplit.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::vector<std::string> rsplit(std::string_view str,
                                                                  std::size_t max_split = std::string::npos) noexcept;

    /**
     * @brief Splits a string into substrings using a specified delimiter, starting from the end of the string.
     *
     * The input string is split into substrings using the specified delimiter.
     * The substrings are returned as a vector of strings.
     * An optional argument \p max_split can be used to specify the maximum number of splits to perform.
     * If \p max_split is equal to \c std::string::npos, all possible splits are performed.
     * The splitting starts from the end of the string and proceeds towards the beginning.
     * The behavior of the split can be controlled using the \p options parameter.
     *
     * @param str The input string to split.
     * @param delimiter The delimiter used to split the string.
     * @param max_split The maximum number of splits to perform (optional).
     * @param options A bitwise combination of StringSplitOptions values that specifies
     * options for splitting strings (optional).
     *
     * @return A vector of strings containing the substrings in reverse order.
     *
     * @sa https://www.w3schools.com/python/ref_string_rsplit.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::vector<std::string>
      rsplit(std::string_view str, std::string_view delimiter, std::size_t max_split = std::string::npos,
             StringSplitOptions options = StringSplitOptions::none) noexcept;

    /**
     * @brief Splits a string into substrings using a specified delimiter, starting from the end of the string.
     *
     * The input string is split into substrings using the specified delimiter.
     * The substrings are returned as a vector of strings.
     * The splitting starts from the end of the string and proceeds towards the beginning.
     * The behavior of the split can be controlled using the \p options parameter.
     *
     * @param str The input string to split.
     * @param delimiter The delimiter used to split the string.
     * @param options A bitwise combination of StringSplitOptions values that specifies options for splitting strings.
     *
     * @return A vector of strings containing the substrings in reverse order.
     *
     * @sa https://www.w3schools.com/python/ref_string_rsplit.asp
     */
    [[nodiscard]] inline std::vector<std::string> rsplit(const std::string_view str, const std::string_view delimiter,
                                                         const StringSplitOptions options) noexcept
    {
        return rsplit(str, delimiter, std::string::npos, options);
    }
}

/**
 * @brief Bitwise OR operator for the \c StringSplitOptions enumeration.
 *
 * @param lhs The left-hand side operand.
 * @param rhs The right-hand side operand.
 *
 * @return The result of the bitwise OR operation.
 * @private
 */
[[nodiscard]] constexpr strpy::StringSplitOptions operator|(const strpy::StringSplitOptions lhs,
                                                            const strpy::StringSplitOptions rhs) noexcept
{
    return static_cast<strpy::StringSplitOptions>(static_cast<std::underlying_type_t<strpy::StringSplitOptions>>(lhs) |
                                                  static_cast<std::underlying_type_t<strpy::StringSplitOptions>>(rhs));
}

/**
 * @brief Bitwise AND operator for the \c StringSplitOptions enumeration.
 *
 * @param lhs The left-hand side operand.
 * @param rhs The right-hand side operand.
 *
 * @return The result of the bitwise AND operation.
 * @private
 */
[[nodiscard]] constexpr strpy::StringSplitOptions operator&(const strpy::StringSplitOptions lhs,
                                                            const strpy::StringSplitOptions rhs) noexcept
{
    return static_cast<strpy::StringSplitOptions>(static_cast<std::underlying_type_t<strpy::StringSplitOptions>>(lhs) &
                                                  static_cast<std::underlying_type_t<strpy::StringSplitOptions>>(rhs));
}
