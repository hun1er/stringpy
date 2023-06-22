/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for swapping the case of characters in a string.
 *
 * @example swapcase.cpp
 * Demonstrates the use of the swap_case_char() and swap_case() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/export.hpp"
#include <string_view>
#include <string>

namespace strpy
{
    /**
     * @brief Swaps the case of a character.
     *
     * Returns the character with its case swapped.
     * If the input character is lowercase, it returns the uppercase version of the character.
     * If the input character is uppercase, it returns the lowercase version of the character.
     * If the input character is not a letter, it returns the input character unchanged.
     *
     * @param ch The character to swap case.
     *
     * @return The character with its case swapped.
     */
    [[nodiscard]] STRINGPY_EXPORT std::string::value_type swap_case_char(std::string::value_type ch) noexcept;

    /**
     * @brief Swaps the case of all characters in a string.
     *
     * Returns a new string with all characters case swapped.
     * It uses the \ref strpy::swap_case_char function to swap the case of each character in the input string.
     *
     * @param str The string to swap case.
     *
     * @return A new string with all characters case swapped.
     *
     * @sa https://www.w3schools.com/python/ref_string_swapcase.asp
     */
    [[nodiscard]] STRINGPY_EXPORT std::string swap_case(std::string_view str) noexcept;
}
