/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/capitalize.hpp"
#include "stringpy/ctype.hpp"
#include "stringpy/stype.hpp"

namespace strpy
{
    std::string capitalize(const std::string_view str) noexcept
    {
        if (str.empty()) {
            return {};
        }

        auto result = to_lower(str);
        auto& first_char = result.front();
        first_char = to_upper_char<std::string::value_type>(first_char);

        return result;
    }
}
