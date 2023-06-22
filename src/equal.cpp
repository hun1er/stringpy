/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/equal.hpp"
#include <algorithm>

namespace
{
    /** @brief Type alias for a function pointer to strpy::equal_char or strpy::equal_char_icase */
    using Comparator = decltype(&strpy::equal_char<std::string_view::value_type>);

    bool equal_impl(const std::string_view str1, const std::string_view str2, const std::size_t start, std::size_t end,
                    const Comparator comp) noexcept
    {
        if ((start != 0) && ((start > end) || (start >= str1.size()))) {
            return false;
        }

        if (end = std::min(end, str1.size()); (end - start) != str2.size()) {
            return false;
        }

        return std::equal(str1.cbegin() + static_cast<std::string_view::difference_type>(start),
                          str1.cbegin() + static_cast<std::string_view::difference_type>(end), str2.cbegin(), comp);
    }
}

namespace strpy
{
    bool equal(const std::string_view str1, const std::string_view str2, const std::size_t start,
               const std::size_t end) noexcept
    {
        return equal_impl(str1, str2, start, end, equal_char<std::string_view::value_type>);
    }

    bool equal_icase(const std::string_view str1, const std::string_view str2, const std::size_t start,
                     const std::size_t end) noexcept
    {
        return equal_impl(str1, str2, start, end, equal_char_icase<std::string_view::value_type>);
    }
}
