/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides a function for expanding tabs in a string to spaces.
 *
 * @example expandtabs.cpp
 * Demonstrates the use of the expand_tabs() function from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <cstddef>
#include <string>

namespace strpy
{
    /**
     * @brief Expands tabs in a string to spaces.
     *
     * Returns a new string that is the original string
     * with all tab characters replaced by the appropriate number of spaces.
     * The number of spaces is determined by the \p tab_size parameter.
     *
     * @param str The input string containing tabs to be expanded.
     * @param tab_size The number of spaces to replace each tab character (optional).
     *
     * @return A new string that is the original string with all tabs expanded to spaces.
     *
     * @sa https://www.w3schools.com/python/ref_string_expandtabs.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string expand_tabs(std::string_view str, std::size_t tab_size = 8) noexcept;
}
