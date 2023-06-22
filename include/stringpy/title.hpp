/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides a function for transforming a string to title case.
 *
 * @example title.cpp
 * Demonstrates the use of the title() function from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <string>

namespace strpy
{
    /**
     * @brief Returns a string where the first character of each word is uppercase and the rest are lowercase.
     *
     * @param str The input string to transform.
     *
     * @return A new string where the first character of each word is uppercase and the rest are lowercase.
     *
     * @sa https://www.w3schools.com/python/ref_string_title.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string title(std::string_view str) noexcept;
}
