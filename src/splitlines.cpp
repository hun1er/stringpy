/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/splitlines.hpp"
#include "stringpy/const.hpp"
#include <algorithm>
#include <cstddef>

namespace
{
    constexpr std::size_t MIN_RESULT_CAPACITY = 2;
    constexpr std::size_t AVERAGE_LINE_LENGTH = 70;
}

namespace strpy
{
    std::vector<std::string> split_lines(const std::string_view str, const bool keep_ends) noexcept
    {
        std::vector<std::string> result{};
        result.reserve(std::max(MIN_RESULT_CAPACITY, str.size() / AVERAGE_LINE_LENGTH));

        std::size_t start = 0;
        auto end = std::string_view::npos;

        const auto str_size = str.size();
        const std::size_t endline_offset = keep_ends ? 1 : 0;

        // cppcheck-suppress redundantInitialization
        while ((end = str.find_first_of("\r\n", start)) != std::string_view::npos) {
            result.emplace_back(str.substr(start, (end - start) + endline_offset));
            start = (end + 1);

            if ((CARRIAGE_RETURN == str[end]) && (start < str_size) && (LINE_FEED == str[start])) {
                if (keep_ends) {
                    result.back() += LINE_FEED;
                }

                ++start;
            }
        }

        if (start < str_size) {
            result.emplace_back(str.substr(start));
        }

        return result;
    }
}
