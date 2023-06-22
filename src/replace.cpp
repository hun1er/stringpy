/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/replace.hpp"
#include "stringpy/find.hpp"

namespace
{
    /** @brief Type alias for a function pointer to strpy::find or strpy::find_icase */
    using FindFunc = decltype(&strpy::find);

    std::string replace_impl(const std::string_view str, const std::string_view old_value,
                             const std::string_view new_value, std::size_t count, const FindFunc find) noexcept
    {
        if (old_value.empty()) {
            return std::string{str};
        }

        std::string result{str};
        std::size_t start = 0;
        constexpr auto end = std::string_view::npos;

        while (((start = find(result, old_value, start, end)) != std::string::npos) && (count != 0)) {
            result.replace(start, old_value.length(), new_value);
            start += new_value.length();
            --count;
        }

        return result;
    }
}

namespace strpy
{
    std::string replace(const std::string_view str, const std::string_view old_value, const std::string_view new_value,
                        const std::size_t count) noexcept
    {
        return replace_impl(str, old_value, new_value, count, find);
    }

    std::string replace_icase(const std::string_view str, const std::string_view old_value,
                              const std::string_view new_value, const std::size_t count) noexcept
    {
        return replace_impl(str, old_value, new_value, count, find_icase);
    }
}
