/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/count.hpp"
#include "stringpy/find.hpp"
#include <algorithm>

namespace
{
    /** @brief Type alias for a function pointer to strpy::find or strpy::find_icase */
    using FindFunc = decltype(&strpy::find);

    std::size_t count_impl(const std::string_view str, const std::string_view sub, std::size_t start, std::size_t end,
                           const FindFunc find) noexcept
    {
        if (str.empty() || (start > end) || (start >= str.size()) || (sub.size() > str.size())) {
            return 0;
        }

        if (sub.empty()) {
            end = std::min(end, str.size());
            return (end - start) + 1;
        }

        std::size_t result = 0;
        const auto sub_size = sub.size();

        while ((start = find(str, sub, start, end)) != std::string_view::npos) {
            start += sub_size;
            ++result;
        }

        return result;
    }
}

namespace strpy
{
    std::size_t count(const std::string_view str, const std::string_view sub, const std::size_t start,
                      const std::size_t end) noexcept
    {
        return count_impl(str, sub, start, end, find);
    }

    std::size_t count_icase(const std::string_view str, const std::string_view sub, const std::size_t start,
                            const std::size_t end) noexcept
    {
        return count_impl(str, sub, start, end, find_icase);
    }
}
