/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/expandtabs.hpp"
#include "stringpy/const.hpp"
#include "stringpy/replace.hpp"

namespace strpy
{
    std::string expand_tabs(const std::string_view str, const std::size_t tab_size) noexcept
    {
        if (str.empty()) {
            return {};
        }

        if (0 == tab_size) {
            return replace(str, TAB_STR, EMPTY_STR);
        }

        std::string result{};
        result.reserve(str.size());
        std::size_t column = 0;

        for (const auto ch : str) {
            if (TAB == ch) {
                const auto spaces = tab_size - (column % tab_size);
                result.append(spaces, SPACE);
                column += spaces;
            }
            else {
                result.push_back(ch);

                if ((LINE_FEED == ch) || (CARRIAGE_RETURN == ch)) {
                    column = 0;
                }
                else {
                    ++column;
                }
            }
        }

        return result;
    }
}
