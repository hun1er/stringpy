/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides constants for string manipulation.
 */

#pragma once

namespace strpy
{
    /** @brief Empty string. */
    constexpr auto* EMPTY_STR = "";

    /** @brief Tab character. */
    constexpr auto TAB = '\t';

    /** @brief Tab character as a string. */
    constexpr auto* TAB_STR = "\t";

    /** @brief Space character. */
    constexpr auto SPACE = ' ';

    /** @brief Space character as a string. */
    constexpr auto* SPACE_STR = " ";

    /** @brief End-of-string character. */
    constexpr auto EOS = '\0';

    /** @brief Line feed character. */
    constexpr auto LINE_FEED = '\n';

    /** @brief Line feed character as a string. */
    constexpr auto* LINE_FEED_STR = "\n";

    /** @brief Carriage return character. */
    constexpr auto CARRIAGE_RETURN = '\r';

    /** @brief Carriage return character as a string. */
    constexpr auto* CARRIAGE_RETURN_STR = "\r";

    /** @brief String containing all space characters. */
    constexpr auto* SPACE_CHARS = " \f\n\r\t\v";

#ifdef _WIN32
    /** @brief Correct path separator for Windows systems. */
    constexpr auto CORRECT_PATH_SEP = '\\';

    /** @brief Correct path separator for Windows systems as a string. */
    constexpr auto* CORRECT_PATH_SEP_STR = "\\";

    /** @brief Incorrect path separator for Windows systems. */
    constexpr auto INCORRECT_PATH_SEP = '/';

    /** @brief Incorrect path separator for Windows systems as a string. */
    constexpr auto* INCORRECT_PATH_SEP_STR = "/";
#else
    /** @brief Correct path separator for non-Windows systems. */
    constexpr auto CORRECT_PATH_SEP = '/';

    /** @brief Correct path separator for non-Windows systems as a string. */
    constexpr auto* CORRECT_PATH_SEP_STR = "/";

    /** @brief Incorrect path separator for non-Windows systems. */
    constexpr auto INCORRECT_PATH_SEP = '\\';

    /** @brief Incorrect path separator for non-Windows systems as a string. */
    constexpr auto* INCORRECT_PATH_SEP_STR = "\\";
#endif
}
