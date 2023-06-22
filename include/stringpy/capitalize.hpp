/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides a function for capitalizing the first character of a string.
 *
 * @example capitalize.cpp
 * Demonstrates the use of the capitalize() function from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <string>

namespace strpy
{
    /**
     * @brief Capitalizes the first character of a string and lowercases the rest.
     *
     * Takes a string as input and returns a new string with the first character capitalized
     * and the rest of the characters in lowercase.
     * If the input string is empty, an empty string is returned.
     *
     * @param str The input string to capitalize.
     *
     * @return A new string with the first character capitalized and the rest of the characters in lowercase.
     *
     * @sa https://www.w3schools.com/python/ref_string_capitalize.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string capitalize(std::string_view str) noexcept;
}
