/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for finding substrings and characters within a string.
 *
 * @example find.cpp
 * Demonstrates the use of various find functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>

namespace strpy
{
    /**
     * @brief Finds the first occurrence of a substring within a string.
     *
     * Returns the index of the first occurrence of the substring within the string,
     * starting at position \p start and ending at position \p end.
     * If the substring is not found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param sub The substring to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The index of the first occurrence of the substring, or \c std::string_view::npos if not found.
     *
     * @sa https://www.w3schools.com/python/ref_string_find.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find(std::string_view str, std::string_view sub, std::size_t start = 0,
                                                   std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the first occurrence of a substring within a string, ignoring case.
     *
     * Returns the index of the first occurrence of the substring within the string,
     * starting at position \p start and ending at position \p end.
     * If the substring is not found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param sub The substring to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The index of the first occurrence of the substring, or \c std::string_view::npos if not found.
     *
     * @sa https://www.w3schools.com/python/ref_string_find.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_icase(std::string_view str, std::string_view sub,
                                                         std::size_t start = 0,
                                                         std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the last occurrence of a substring within a string.
     *
     * Returns the index of the last occurrence of the substring within the string,
     * starting at position \p start and ending at position \p end.
     * If the substring is not found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param sub The substring to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The index of the last occurrence of the substring, or \c std::string_view::npos if not found.
     *
     * @sa https://www.w3schools.com/python/ref_string_rfind.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t rfind(std::string_view str, std::string_view sub, std::size_t start = 0,
                                                    std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the last occurrence of a substring within a string, ignoring case.
     *
     * Returns the index of the last occurrence of the substring within the string,
     * starting at position \p start and ending at position \p end, ignoring case.
     * If the substring is not found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param sub The substring to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The index of the last occurrence of the substring, or \c std::string_view::npos if not found.
     *
     * @sa https://www.w3schools.com/python/ref_string_rfind.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t rfind_icase(std::string_view str, std::string_view sub,
                                                          std::size_t start = 0,
                                                          std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the first occurrence of any character from a set of characters within a string.
     *
     * Returns the position of the first occurrence of any character from the set of characters within the string,
     * starting at position \p start and ending at position \p end.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the first occurrence of any character from chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_first_of(std::string_view str, std::string_view chars,
                                                            std::size_t start = 0,
                                                            std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the first occurrence of any character from a set of characters within a string, ignoring case.
     *
     * Returns the position of the first occurrence of any character from the set of characters within the string,
     * starting at position \p start and ending at position \p end, ignoring case.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the first occurrence of any character from chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_first_of_icase(std::string_view str, std::string_view chars,
                                                                  std::size_t start = 0,
                                                                  std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the first occurrence of a character not in a set of characters within a string.
     *
     * Returns the position of the first occurrence of a character not in the set of characters within the string,
     * starting at position \p start and ending at position \p end.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to exclude from the search.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the first occurrence of a character not in chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_first_not_of(std::string_view str, std::string_view chars,
                                                                std::size_t start = 0,
                                                                std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the first occurrence of a character not in a set of characters within a string, ignoring case.
     *
     * Returns the position of the first occurrence of a character not in the set of characters within the string,
     * starting at position \p start and ending at position \p end, ignoring case.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to exclude from the search.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the first occurrence of a character not in chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t
      find_first_not_of_icase(std::string_view str, std::string_view chars, std::size_t start = 0,
                              std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the last occurrence of any character from a set of characters within a string.
     *
     * Returns the position of the last occurrence of any character from the set of characters within the string,
     * starting at position \p start and ending at position \p end.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the last occurrence of any character from chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_last_of(std::string_view str, std::string_view chars,
                                                           std::size_t start = 0,
                                                           std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the last occurrence of any character from a set of characters within a string, ignoring case.
     *
     * Returns the position of the last occurrence of any character from the set of characters within the string,
     * starting at position \p start and ending at position \p end, ignoring case.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to search for.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the last occurrence of any character from chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_last_of_icase(std::string_view str, std::string_view chars,
                                                                 std::size_t start = 0,
                                                                 std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the last occurrence of a character not in a set of characters within a string.
     *
     * Returns the position of the last occurrence of a character not in the set of characters within the string,
     * starting at position \p start and ending at position \p end.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to exclude from the search.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the last occurrence of a character not in chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_last_not_of(std::string_view str, std::string_view chars,
                                                               std::size_t start = 0,
                                                               std::size_t end = std::string_view::npos) noexcept;

    /**
     * @brief Finds the last occurrence of a character not in a set of characters within a string, ignoring case.
     *
     * Returns the position of the last occurrence of a character not in the set of characters within the string,
     * starting at position \p start and ending at position \p end, ignoring case.
     * If no such character is found, \c std::string_view::npos is returned.
     *
     * @param str The string to search within.
     * @param chars The set of characters to exclude from the search.
     * @param start The starting position for the search (optional).
     * @param end The ending position for the search (optional).
     *
     * @return The position of the last occurrence of a character not in chars within str,
     * or \c std::string_view::npos if no such character is found.
     */
    [[nodiscard]] STRINGPY_EXPORT std::size_t find_last_not_of_icase(std::string_view str, std::string_view chars,
                                                                     std::size_t start = 0,
                                                                     std::size_t end = std::string_view::npos) noexcept;
}
