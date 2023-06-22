/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for checking the properties of strings.
 *
 * @example stype.cpp
 * Demonstrates the use of various character and string classification functions from the strpy namespace.
 */

#pragma once

#include "stringpy/const.hpp"
#include "stringpy/ctype.hpp"
#include "stringpy/export.hpp"
#include <string_view>
#include <algorithm>
#include <string>

namespace strpy
{
    /**
     * @brief Checks if the given string is a valid identifier according to Python rules.
     *
     * A valid identifier is a non-empty string that starts with an underscore or an alphabetic character
     * and only contains alphanumeric characters or underscores.
     *
     * @param str The string to check.
     *
     * @return \c true if the string is a valid identifier, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isidentifier.asp
     */
    [[nodiscard]] STRINGPY_EXPORT bool is_identifier(std::string_view str) noexcept;

    /**
     * @brief Checks if the given string is a titlecased string according to Python rules.
     *
     * A titlecased string is a string that has uppercase characters at the beginning of each word
     * and lowercase characters for the rest of the word.
     * Symbols and numbers are ignored.
     *
     * @param str The string to check.
     *
     * @return \c true if the string is a titlecased string, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_istitle.asp
     */
    [[nodiscard]] STRINGPY_EXPORT bool is_title(std::string_view str) noexcept;

    /**
     * @brief Checks if all characters in the given string are alphanumeric.
     *
     * An alphanumeric character is a character that is either a letter or a digit.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are alphanumeric, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isalnum.asp
     */
    [[nodiscard]] inline bool is_alnum(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_alnum_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are alphabetic.
     *
     * An alphabetic character is a character that is a letter.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are alphabetic, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isalpha.asp
     */
    [[nodiscard]] inline bool is_alpha(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_alpha_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are ASCII characters.
     *
     * An ASCII character is a character that is part of the ASCII table.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are ASCII characters, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isascii.asp
     */
    [[nodiscard]] inline bool is_ascii(const std::string_view str) noexcept
    {
        return str.empty() || std::all_of(str.cbegin(), str.cend(), is_ascii_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are blank.
     *
     * A blank character is a character that is a space or a tab.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are blank, \c false otherwise.
     */
    [[nodiscard]] inline bool is_blank(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_blank_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are control characters.
     *
     * A control character is a character that does not represent a printable symbol
     * or character but serves to initiate a particular action.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are control characters, \c false otherwise.
     */
    [[nodiscard]] inline bool is_cntrl(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_cntrl_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are decimal digits.
     *
     * A decimal digit is a character that represents a decimal number (0-9).
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are decimal digits, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isdigit.asp
     */
    [[nodiscard]] inline bool is_digit(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_digit_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if the given string is empty or contains only whitespace characters.
     *
     * A whitespace character is a character that represents a space (e.g. ' ', '\\t', '\\n').
     *
     * @param str The string to check.
     *
     * @return \c true if the string is empty or contains only whitespace characters, \c false otherwise.
     */
    [[nodiscard]] inline bool is_empty_or_space(const std::string_view str) noexcept
    {
        return str.empty() || std::all_of(str.cbegin(), str.cend(), is_space_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are graphical characters.
     *
     * A graphical character is a character that is printable, except for space.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are graphical characters, \c false otherwise.
     */
    [[nodiscard]] inline bool is_graph(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_graph_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are lowercase.
     *
     * A lowercase character is a character that is a lowercase letter.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are lowercase, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_islower.asp
     */
    [[nodiscard]] inline bool is_lower(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_lower_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if a given string is null or empty.
     *
     * An empty string is a string that has no characters.
     *
     * @tparam Char The character type of the string.
     *
     * @param str The string to check.
     *
     * @return \c true if the string is null or empty, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] constexpr bool is_null_or_empty(const Char* const str) noexcept
    {
        return (nullptr == str) || (EOS == *str);
    }

    /**
     * @brief Checks if a given string is null, empty or contains only whitespace characters.
     *
     * An empty string is a string that has no characters.
     *
     * @tparam Char The character type of the string.
     *
     * @param str The string to check.
     *
     * @return \c true if the string is null, empty or contains only whitespace characters, \c false otherwise.
     */
    template <typename Char = std::string::value_type>
    [[nodiscard]] bool is_null_or_space(const Char* const str) noexcept
    {
        return is_null_or_empty<Char>(str) || // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
               std::all_of(str, (str + std::char_traits<Char>::length(str)), is_space_char<Char>);
    }

    /**
     * @brief Checks if all characters in the given string are printable characters.
     *
     * A printable character is a character that is not a control character.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are printable characters, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isprintable.asp
     */
    [[nodiscard]] inline bool is_printable(const std::string_view str) noexcept
    {
        return str.empty() || std::all_of(str.cbegin(), str.cend(), is_printable_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are punctuation characters.
     *
     * A punctuation character is a character that is not a letter, digit or space.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are punctuation characters, \c false otherwise.
     */
    [[nodiscard]] inline bool is_punct(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_punct_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are whitespace characters.
     *
     * A whitespace character is a character that represents horizontal or vertical space.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are whitespace characters, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isspace.asp
     */
    [[nodiscard]] inline bool is_space(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_space_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are uppercase.
     *
     * An uppercase character is a character that is an uppercase letter.
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are uppercase, \c false otherwise.
     *
     * @sa https://www.w3schools.com/python/ref_string_isupper.asp
     */
    [[nodiscard]] inline bool is_upper(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_upper_char<std::string_view::value_type>);
    }

    /**
     * @brief Checks if all characters in the given string are hexadecimal digits.
     *
     * A hexadecimal digit is a character that represents a hexadecimal number (0-9, a-f, A-F).
     *
     * @param str The string to check.
     *
     * @return \c true if all characters in the string are hexadecimal digits, \c false otherwise.
     */
    [[nodiscard]] inline bool is_xdigit(const std::string_view str) noexcept
    {
        return (!str.empty()) && std::all_of(str.cbegin(), str.cend(), is_xdigit_char<std::string_view::value_type>);
    }

    /**
     * @brief Converts a string to lowercase.
     *
     * Takes a string as input and returns a new string
     * where all the characters are converted to lowercase.
     *
     * @param str The input string to convert to lowercase.
     *
     * @return A new string where all the characters are lowercase.
     */
    [[nodiscard]] STRINGPY_EXPORT std::string to_lower(std::string_view str) noexcept;

    /**
     * @brief Converts a string to uppercase.
     *
     * Takes a string as input and returns a new string
     * where all the characters are converted to uppercase.
     *
     * @param str The input string to convert to uppercase.
     *
     * @return A new string where all the characters are uppercase.
     */
    [[nodiscard]] STRINGPY_EXPORT std::string to_upper(std::string_view str) noexcept;
}
