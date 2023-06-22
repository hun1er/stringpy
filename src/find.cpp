/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/find.hpp"
#include "stringpy/equal.hpp"
#include <algorithm>
#include <iterator>
#include <string>

namespace
{
    std::size_t find_forward(const std::string_view str, const std::string_view sub) noexcept
    {
        return str.find(sub);
    }

    std::size_t find_reverse(const std::string_view str, const std::string_view sub) noexcept
    {
        return str.rfind(sub);
    }

    std::size_t find_forward_icase(const std::string_view str, const std::string_view sub) noexcept
    {
        if (sub.empty()) {
            return 0;
        }

        const auto& it = std::search(str.cbegin(), str.cend(), sub.cbegin(), sub.cend(),
                                     strpy::equal_char_icase<std::string_view::value_type>);

        return it == str.cend() ? std::string_view::npos : static_cast<std::size_t>(it - str.cbegin());
    }

    std::size_t find_reverse_icase(const std::string_view str, const std::string_view sub) noexcept
    {
        if (sub.empty()) {
            return str.size();
        }

        const auto& it = std::search(str.crbegin(), str.crend(), sub.crbegin(), sub.crend(),
                                     strpy::equal_char_icase<std::string_view::value_type>);

        return it == str.crend() ? std::string_view::npos : (static_cast<std::size_t>(str.crend() - it) - sub.size());
    }

    /** @brief Type alias for a function pointer to find_* */
    using FindFunc = decltype(&find_forward);

    std::size_t find_impl(std::string_view str, const std::string_view sub, const std::size_t start, std::size_t end,
                          const FindFunc find) noexcept
    {
        if ((start != 0) && ((start > end) || (start >= str.size()))) {
            return std::string_view::npos;
        }

        if ((start != 0) || (end != std::string_view::npos)) {
            end = std::min(end, str.size());
            str = str.substr(start, end - start);
        }

        if (str.size() < sub.size()) {
            return std::string_view::npos;
        }

        if (const auto result = find(str, sub); result != std::string_view::npos) {
            return start + result;
        }

        return std::string_view::npos;
    }
}

namespace strpy
{
    std::size_t find(const std::string_view str, const std::string_view sub, const std::size_t start,
                     const std::size_t end) noexcept
    {
        return find_impl(str, sub, start, end, find_forward);
    }

    std::size_t find_icase(const std::string_view str, const std::string_view sub, const std::size_t start,
                           const std::size_t end) noexcept
    {
        return find_impl(str, sub, start, end, find_forward_icase);
    }

    std::size_t rfind(const std::string_view str, const std::string_view sub, const std::size_t start,
                      const std::size_t end) noexcept
    {
        return find_impl(str, sub, start, end, find_reverse);
    }

    std::size_t rfind_icase(const std::string_view str, const std::string_view sub, const std::size_t start,
                            const std::size_t end) noexcept
    {
        return find_impl(str, sub, start, end, find_reverse_icase);
    }

    std::size_t find_first_of(std::string_view str, const std::string_view chars, const std::size_t start,
                              const std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if (end < str.size()) {
            str.remove_suffix(str.size() - end);
        }

        return str.find_first_of(chars, start);
    }

    std::size_t find_first_of_icase(std::string_view str, const std::string_view chars, const std::size_t start,
                                    const std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size()) || chars.empty()) {
            return std::string_view::npos;
        }

        if (end < str.size()) {
            str.remove_suffix(str.size() - end);
        }

        const auto& it =
          std::find_first_of(str.cbegin() + static_cast<std::string_view::difference_type>(start), str.cend(),
                             chars.cbegin(), chars.cend(), equal_char_icase<std::string_view::value_type>);

        return it == str.cend() ? std::string::npos : static_cast<std::size_t>(it - str.cbegin());
    }

    std::size_t find_first_not_of(std::string_view str, const std::string_view chars, const std::size_t start,
                                  const std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if (end < str.size()) {
            str.remove_suffix(str.size() - end);
        }

        return str.find_first_not_of(chars, start);
    }

    std::size_t find_first_not_of_icase(std::string_view str, const std::string_view chars, const std::size_t start,
                                        const std::size_t end) noexcept
    {
        using DiffType = std::string_view::difference_type;

        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if (chars.empty()) {
            return 0;
        }

        if (end < str.size()) {
            str.remove_suffix(str.size() - end);
        }

        const auto& it =
          std::find_if(str.cbegin() + static_cast<DiffType>(start), str.cend(), [&chars](const auto ch1) {
              return std::none_of(chars.cbegin(), chars.cend(), [ch1](const auto ch2) {
                  return equal_char_icase(ch1, ch2);
              });
          });

        return it == str.cend() ? std::string::npos : static_cast<std::size_t>(it - str.cbegin());
    }

    std::size_t find_last_of(std::string_view str, const std::string_view chars, const std::size_t start,
                             std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if ((start != 0) || (end != std::string_view::npos)) {
            end = std::min(end, str.size());
            str = str.substr(start, end - start);
        }

        if (const auto result = str.find_last_of(chars); result != std::string_view::npos) {
            return start + result;
        }

        return std::string_view::npos;
    }

    std::size_t find_last_of_icase(std::string_view str, const std::string_view chars, const std::size_t start,
                                   std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if ((start != 0) || (end != std::string_view::npos)) {
            end = std::min(end, str.size());
            str = str.substr(start, end - start);
        }

        const auto& it = std::find_first_of(str.crbegin(), str.crend(), chars.cbegin(), chars.cend(),
                                            equal_char_icase<std::string_view::value_type>);

        return it == str.crend() ? std::string::npos : (start + (static_cast<std::size_t>(str.crend() - it) - 1));
    }

    std::size_t find_last_not_of(std::string_view str, const std::string_view chars, const std::size_t start,
                                 std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if ((start != 0) || (end != std::string_view::npos)) {
            end = std::min(end, str.size());
            str = str.substr(start, end - start);
        }

        if (const auto result = str.find_last_not_of(chars); result != std::string_view::npos) {
            return start + result;
        }

        return std::string_view::npos;
    }

    std::size_t find_last_not_of_icase(std::string_view str, const std::string_view chars, const std::size_t start,
                                       std::size_t end) noexcept
    {
        if ((start > end) || (start >= str.size())) {
            return std::string_view::npos;
        }

        if ((start != 0) || (end != std::string_view::npos)) {
            end = std::min(end, str.size());
            str = str.substr(start, end - start);
        }

        const auto& it = std::find_if(str.crbegin(), str.crend(), [&chars](const auto ch1) {
            return std::none_of(chars.cbegin(), chars.cend(), [ch1](const auto ch2) {
                return equal_char_icase(ch1, ch2);
            });
        });

        return it == str.crend() ? std::string::npos : (start + (static_cast<std::size_t>(str.crend() - it) - 1));
    }
}
