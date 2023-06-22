/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/title.hpp"
#include "stringpy/ctype.hpp"

namespace strpy
{
    std::string title(const std::string_view str) noexcept
    {
        if (str.empty()) {
            return {};
        }

        std::string result{str};
        auto new_word = true;

        for (auto& ch : result) {
            if (new_word && is_alpha_char(ch)) {
                ch = to_upper_char(ch);
                new_word = false;
            }
            else if ((!is_alnum_char(ch)) && (ch != '\'')) {
                new_word = true;
            }
            else {
                ch = to_lower_char(ch);
            }
        }

        return result;
    }
}
