/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/swapcase.hpp"
#include "stringpy/ctype.hpp"
#include <algorithm>

namespace strpy
{
    std::string::value_type swap_case_char(const std::string::value_type ch) noexcept
    {
        if (is_lower_char(ch)) {
            return to_upper_char<std::string::value_type>(ch);
        }

        if (is_upper_char(ch)) {
            return to_lower_char<std::string::value_type>(ch);
        }

        return ch;
    }

    std::string swap_case(const std::string_view str) noexcept
    {
        if (str.empty()) {
            return {};
        }

        std::string result{str};
        std::transform(result.begin(), result.end(), result.begin(), swap_case_char);

        return result;
    }
}
