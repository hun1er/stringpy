/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for splitting a string at the first or last occurrence of a separator.
 *
 * @example partition.cpp
 * Demonstrates the use of the partition(), partition_icase(), rpartition(),
 * and rpartition_icase() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <string>
#include <tuple>

namespace strpy
{
    /**
     * @brief Splits a string at the first occurrence of a separator.
     *
     * The string is split at the first occurrence of a separator and a tuple is returned
     * containing the part before the separator, the separator itself, and the part after the separator.
     * If the separator is not found, a tuple containing the original string and two empty strings is returned.
     *
     * @param str The string to split.
     * @param sep The separator to split at.
     *
     * @return A tuple containing the part before the separator, the separator itself, and the part after the separator.
     *
     * @sa https://www.w3schools.com/python/ref_string_partition.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::tuple<std::string, std::string, std::string>
      partition(std::string_view str, std::string_view sep) noexcept;

    /**
     * @brief Splits a string at the first occurrence of a separator, ignoring case.
     *
     * The string is split at the first occurrence of a separator and a tuple is returned
     * containing the part before the separator, the separator itself, and the part after the separator.
     * If the separator is not found, a tuple containing two empty strings and the original string is returned.
     *
     * @param str The string to split.
     * @param sep The separator to split at.
     *
     * @return A tuple containing the part before the separator, the separator itself, and the part after the separator.
     *
     * @sa https://www.w3schools.com/python/ref_string_partition.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::tuple<std::string, std::string, std::string>
      partition_icase(std::string_view str, std::string_view sep) noexcept;

    /**
     * @brief Splits a string at the last occurrence of a separator.
     *
     * The string is split at the last occurrence of a separator and a tuple is returned
     * containing the part before the separator, the separator itself, and the part after the separator.
     * If the separator is not found, a tuple containing two empty strings and the original string is returned.
     *
     * @param str The string to split.
     * @param sep The separator to split at.
     *
     * @return A tuple containing the part before the separator, the separator itself, and the part after the separator.
     *
     * @sa https://www.w3schools.com/python/ref_string_rpartition.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::tuple<std::string, std::string, std::string>
      rpartition(std::string_view str, std::string_view sep) noexcept;

    /**
     * @brief Splits a string at the last occurrence of a separator, ignoring case.
     *
     * The string is split at the last occurrence of a separator and a tuple is returned
     * containing the part before the separator, the separator itself, and the part after the separator.
     * If the separator is not found, a tuple containing two empty strings and the original string is returned.
     *
     * @param str The string to split.
     * @param sep The separator to split at.
     *
     * @return A tuple containing the part before the separator, the separator itself, and the part after the separator.
     *
     * @sa https://www.w3schools.com/python/ref_string_rpartition.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::tuple<std::string, std::string, std::string>
      rpartition_icase(std::string_view str, std::string_view sep) noexcept;
}
