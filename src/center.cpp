/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/center.hpp"
#include <algorithm>
#include <iterator>

namespace strpy
{
    std::string center(const std::string_view str, const std::size_t width,
                       const std::string::value_type fill_char) noexcept
    {
        if (str.length() >= width) {
            return std::string{str};
        }

        if (str.empty()) {
            return std::string(width, fill_char); // NOLINT(modernize-return-braced-init-list)
        }

        const auto padding = width - str.length();
        const auto right_padding = padding / 2;
        const auto left_padding = padding - right_padding;

        std::string result{};
        result.reserve(width);

        std::fill_n(std::back_inserter(result), left_padding, fill_char);
        result.append(str);
        std::fill_n(std::back_inserter(result), right_padding, fill_char);

        return result;
    }
}
