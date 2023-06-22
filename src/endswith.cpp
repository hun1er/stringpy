/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/endswith.hpp"
#include "stringpy/equal.hpp"
#include <algorithm>

namespace
{
    /** @brief Type alias for a function pointer to strpy::equal_char or strpy::equal_char_icase */
    using Comparator = decltype(&strpy::equal_char<std::string_view::value_type>);

    bool endswith_impl(std::string_view str, const std::string_view suffix, const std::size_t start, std::size_t end,
                       const Comparator comp) noexcept
    {
        if ((start != 0) && ((start > end) || (start >= str.size()))) {
            return false;
        }

        if ((start != 0) || (end != std::string_view::npos)) {
            end = std::min(end, str.size());
            str = str.substr(start, end - start);
        }

        if (str.size() < suffix.size()) {
            return false;
        }

        return std::equal(suffix.crbegin(), suffix.crend(), str.crbegin(), comp);
    }
}

namespace strpy
{
    bool ends_with(std::string_view str, std::string_view suffix, std::size_t start, std::size_t end) noexcept
    {
        return endswith_impl(str, suffix, start, end, equal_char<std::string_view::value_type>);
    }

    bool ends_with_icase(std::string_view str, std::string_view suffix, std::size_t start, std::size_t end) noexcept
    {
        return endswith_impl(str, suffix, start, end, equal_char_icase<std::string_view::value_type>);
    }
}
