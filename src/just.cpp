/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/just.hpp"

namespace strpy
{
    std::string ljust(const std::string_view str, const std::size_t length,
                      const std::string::value_type fill_char) noexcept
    {
        std::string result{str};
        const auto result_size = result.size();

        if (result_size >= length) {
            return result;
        }

        result.reserve(length);
        result.append(length - result_size, fill_char);

        return result;
    }

    std::string rjust(const std::string_view str, const std::size_t length,
                      const std::string::value_type fill_char) noexcept
    {
        std::string result{str};
        const auto result_size = result.size();

        if (result_size >= length) {
            return result;
        }

        result.reserve(length);
        result.insert(0, length - result_size, fill_char);

        return result;
    }
}
