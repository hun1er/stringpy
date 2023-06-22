/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for character manipulation and classification.
 *
 * @example ctype.cpp
 * Demonstrates the use of various character classification and conversion functions from the strpy namespace.
 */

#pragma once

#include <cctype>
#include <cstdint>
#include <string>

namespace strpy
{
    /**
     * @brief Checks if the given character is alphanumeric.
     *
     * An alphanumeric character is a character that is either a letter or a digit.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is alphanumeric, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_alnum_char(const Char ch) noexcept
    {
        return std::isalnum(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is an alphabetic character.
     *
     * An alphabetic character is a character that is a letter.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is an alphabetic character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_alpha_char(const Char ch) noexcept
    {
        return std::isalpha(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is an ASCII character.
     *
     * An ASCII character is a character that is part of the ASCII table.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is an ASCII character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] constexpr bool is_ascii_char(const Char ch) noexcept
    {
        constexpr std::uint32_t ascii_mask = 0x7FU;
        return 0U == (static_cast<std::uint32_t>(ch) & (~ascii_mask));
    }

    /**
     * @brief Checks if the given character is a blank character.
     *
     * A blank character is a space or a tab.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is a blank character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_blank_char(const Char ch) noexcept
    {
        return std::isblank(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is a control character.
     *
     * A control character is a non-printable character that is used to control the behavior of devices.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is a control character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_cntrl_char(const Char ch) noexcept
    {
        return std::iscntrl(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character are decimal digit.
     *
     * A decimal digit is a character that represents a decimal number (0-9).
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if all characters in the string are decimal digits, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_digit_char(const Char ch) noexcept
    {
        return std::isdigit(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character has a graphical representation.
     *
     * A graphical character is a printable character that is not a space.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character has a graphical representation, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_graph_char(const Char ch) noexcept
    {
        return std::isgraph(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is a lowercase character.
     *
     * A lowercase character is a character that is a lowercase letter.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is a lowercase character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_lower_char(const Char ch) noexcept
    {
        return std::islower(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is printable.
     *
     * A printable character is a character that has a visual representation.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is printable, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_printable_char(const Char ch) noexcept
    {
        return std::isprint(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is a punctuation character.
     *
     * A punctuation character is a printable character that is not a letter, digit or space.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is a punctuation character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_punct_char(const Char ch) noexcept
    {
        return std::ispunct(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is a whitespace character.
     *
     * A whitespace character is a blank space or an invisible separator.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is a whitespace character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_space_char(const Char ch) noexcept
    {
        return std::isspace(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is an uppercase character.
     *
     * An uppercase character is a character that is an uppercase letter.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is an uppercase character, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_upper_char(const Char ch) noexcept
    {
        return std::isupper(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Checks if the given character is a hexadecimal digit.
     *
     * A hexadecimal digit is a character that represents a number in base 16.
     * The function uses the template parameter to determine the type of the character to check.
     *
     * @tparam Char The type of the character to check.
     *
     * @param ch The character to check.
     *
     * @return \c true if the character is a hexadecimal digit, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_xdigit_char(const Char ch) noexcept
    {
        return std::isxdigit(static_cast<unsigned char>(ch)) != 0;
    }

    /**
     * @brief Converts a character to lowercase.
     *
     * The function uses the \c std::tolower function to perform the conversion.
     *
     * @tparam Char The type of the character to convert (optional).
     * @tparam Result The type of the result of the conversion (optional).
     *
     * @param ch The character to convert.
     *
     * @return The lowercase version of the input character.
     */
    template <typename Char = std::string::value_type, typename Result = Char>
    [[nodiscard]] Result to_lower_char(const std::string::value_type ch) noexcept
    {
        if constexpr (std::is_same_v<Result, decltype(std::tolower(static_cast<unsigned char>(ch)))>) {
            return std::tolower(static_cast<unsigned char>(ch));
        }
        else {
            return static_cast<Result>(std::tolower(static_cast<unsigned char>(ch)));
        }
    }

    /**
     * @brief Converts a character to uppercase.
     *
     * The function uses the \c std::toupper function to perform the conversion.
     *
     * @tparam Char The type of the character to convert (optional).
     * @tparam Result The type of the result of the conversion (optional).
     *
     * @param ch The character to convert.
     *
     * @return The uppercase version of the input character.
     */
    template <typename Char = std::string::value_type, typename Result = Char>
    [[nodiscard]] Result to_upper_char(const Char ch) noexcept
    {
        if constexpr (std::is_same_v<Result, decltype(std::toupper(static_cast<unsigned char>(ch)))>) {
            return std::toupper(static_cast<unsigned char>(ch));
        }
        else {
            return static_cast<Result>(std::toupper(static_cast<unsigned char>(ch)));
        }
    }
}
