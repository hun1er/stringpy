/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides a function for centering a string within a field of a given width.
 *
 * @example center.cpp
 * Demonstrates the use of the center() function from the strpy namespace.
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
     * @brief Centers a string within a field of a given width.
     *
     * Returns a new string that is centered within a field of a given width.
     * The field is padded with a specified fill character (default is space).
     * If the input string is longer than the specified width, it is returned unchanged.
     *
     * @param str The input string to be centered.
     * @param width The width of the field.
     * @param fill_char The character to fill the padding (optional).
     *
     * @return A new string that is centered within a field of the given width.
     *
     * @sa https://www.w3schools.com/python/ref_string_center.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string center(std::string_view str, std::size_t width,
                                                     std::string::value_type fill_char = SPACE) noexcept;
}
