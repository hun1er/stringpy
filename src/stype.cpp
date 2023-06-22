/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/stype.hpp"

namespace
{
    constexpr std::string_view::value_type UNDERSCORE = '_';

    bool isalnum_or_underscore(const std::string_view::value_type ch) noexcept
    {
        return (UNDERSCORE == ch) || strpy::is_alnum_char<std::string_view::value_type>(ch);
    }
}

namespace strpy
{
    bool is_identifier(const std::string_view str) noexcept
    {
        if (str.empty() ||
            ((str.front() != UNDERSCORE) && (!is_alpha_char<std::string_view::value_type>(str.front())))) {
            return false;
        }

        return std::all_of(str.cbegin(), str.cend(), isalnum_or_underscore);
    }

    bool is_title(const std::string_view str) noexcept
    {
        auto cased = false;
        auto previous_is_cased = false;

        for (const auto ch : str) {
            if (is_upper_char<std::string_view::value_type>(ch)) {
                if (previous_is_cased) {
                    return false;
                }

                cased = true;
                previous_is_cased = true;
            }
            else if (is_lower_char<std::string_view::value_type>(ch)) {
                if (!previous_is_cased) {
                    return false;
                }

                cased = true;
                previous_is_cased = true; //-V1048
            }
            else if (ch != '\'') {
                previous_is_cased = false;
            }
        }

        return cased;
    }

    std::string to_lower(const std::string_view str) noexcept
    {
        if (str.empty()) {
            return {};
        }

        std::string result{};
        result.resize(str.size());
        std::transform(str.cbegin(), str.cend(), result.begin(), to_lower_char<std::string_view::value_type>);

        return result;
    }

    std::string to_upper(const std::string_view str) noexcept
    {
        if (str.empty()) {
            return {};
        }

        std::string result{};
        result.resize(str.size());
        std::transform(str.cbegin(), str.cend(), result.begin(), to_upper_char<std::string_view::value_type>);

        return result;
    }
}
