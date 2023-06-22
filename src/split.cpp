/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/split.hpp"
#include "stringpy/const.hpp"
#include "stringpy/strip.hpp"
#include <algorithm>

namespace
{
    /** @brief Setting the initial size of the result vector */
    constexpr std::size_t DEFAULT_RESULT_CAPACITY = 24;

    /** @brief Find the position of the delimiter in the string */
    std::size_t find_delimiter(const std::string_view str, const std::string_view delimiter,
                               const std::size_t start) noexcept
    {
        return str.find(delimiter, start);
    }

    /** @brief Find the position of an any space delimiter in the string */
    std::size_t find_delimiter_space(const std::string_view str, const std::string_view /* delimiter */,
                                     const std::size_t start) noexcept
    {
        return str.find_first_of(strpy::SPACE_CHARS, start);
    }

    /** @brief Find the position of the delimiter in the string, searching from right to left */
    std::size_t rfind_delimiter(const std::string_view str, const std::string_view delimiter,
                                const std::size_t start) noexcept
    {
        return str.rfind(delimiter, start);
    }

    /** @brief Find the position of any space delimiter in the string, searching from right to left */
    std::size_t rfind_delimiter_space(const std::string_view str, const std::string_view /* delimiter */,
                                      const std::size_t start) noexcept
    {
        return str.find_last_of(strpy::SPACE_CHARS, start);
    }

    /** @brief Convert a StringSplitOptions value to a bool */
    [[nodiscard]] constexpr bool to_bool(const strpy::StringSplitOptions value) noexcept
    {
        return static_cast<bool>(static_cast<std::underlying_type_t<strpy::StringSplitOptions>>(value));
    }

    /** @brief Add a substring to the result vector, taking into account the options */
    bool add_substring_to_result(std::string_view substring, const strpy::StringSplitOptions options,
                                 std::vector<std::string>& result) noexcept
    {
        if (to_bool(options & strpy::StringSplitOptions::trim) && (!substring.empty())) {
            substring = strpy::strip<std::string_view>(substring);
        }

        if ((!to_bool(options & strpy::StringSplitOptions::remove_empty)) || (!substring.empty())) {
            result.emplace_back(substring);
            return true;
        }

        return false;
    }

    /** @brief Type alias for a function pointer to find_delimiter */
    using FindDelimiterFunc = decltype(&find_delimiter);

    /** @brief Split a string using a custom delimiter search function */
    std::vector<std::string> split_impl(const std::string_view str, const std::string_view delimiter,
                                        std::size_t maxsplit, const strpy::StringSplitOptions options,
                                        const FindDelimiterFunc find) noexcept
    {
        if (str.empty()) {
            return {};
        }

        if (delimiter.empty()) {
            std::vector<std::string> result{};
            result.emplace_back(str);

            return result;
        }

        std::size_t start = 0;
        auto end = std::string_view::npos;

        const auto str_size = str.size();
        const auto delimiter_size = delimiter.size();

        std::vector<std::string> result{};
        result.reserve(maxsplit == std::string::npos ? DEFAULT_RESULT_CAPACITY : (maxsplit + 1));

        while ((start < str_size) && (maxsplit != 0)) {
            if (end = find(str, delimiter, start); std::string_view::npos == end) {
                break;
            }

            if (add_substring_to_result(str.substr(start, end - start), options, result)) {
                --maxsplit;
            }

            start = end + delimiter_size;
        }

        if (start < str_size) {
            result.emplace_back(str.substr(start));
        }
        else if ((start == str_size) && (!to_bool(options & strpy::StringSplitOptions::remove_empty))) {
            result.emplace_back(strpy::EMPTY_STR);
        }

        return result;
    }

    /** @brief Type alias for a function pointer to rfind_delimiter */
    using RFindDelimiterFunc = decltype(&rfind_delimiter);

    /** @brief Split a string from the end using a custom delimiter search function */
    std::vector<std::string> rsplit_impl(const std::string_view str, const std::string_view delimiter,
                                         std::size_t maxsplit, const strpy::StringSplitOptions options,
                                         const RFindDelimiterFunc rfind) noexcept
    {
        if (str.empty()) {
            return {};
        }

        if (delimiter.empty()) {
            std::vector<std::string> result{};
            result.emplace_back(str);

            return result;
        }

        const auto delimiter_size = delimiter.size();
        auto start = std::string_view::npos;
        auto end = str.size();

        std::vector<std::string> result{};
        result.reserve(maxsplit == std::string::npos ? DEFAULT_RESULT_CAPACITY : (maxsplit + 1));

        while ((end != 0) && (maxsplit != 0)) {
            if (start = rfind(str, delimiter, end - 1); std::string_view::npos == start) {
                break;
            }

            if (const auto& substring = str.substr(start + delimiter_size, end - start - delimiter_size);
                add_substring_to_result(substring, options, result)) {
                --maxsplit;
            }

            end = start;
        }

        if (end > 0) {
            result.emplace_back(str.substr(0, end));
        }
        else if (!to_bool(options & strpy::StringSplitOptions::remove_empty)) {
            result.emplace_back(strpy::EMPTY_STR);
        }

        // Reverse result to have the elements in the correct order after splitting from the end
        std::reverse(result.begin(), result.end());

        return result;
    }
}

namespace strpy
{
    std::vector<std::string> split(const std::string_view str, const std::size_t max_split) noexcept
    {
        return split_impl(str, " ", max_split, StringSplitOptions::trim_remove_empty, find_delimiter_space);
    }

    std::vector<std::string> split(const std::string_view str, const std::string_view delimiter,
                                   const std::size_t max_split, const StringSplitOptions options) noexcept
    {
        return split_impl(str, delimiter, max_split, options, find_delimiter);
    }

    std::vector<std::string> rsplit(const std::string_view str, const std::size_t max_split) noexcept
    {
        return rsplit_impl(str, " ", max_split, StringSplitOptions::trim_remove_empty, rfind_delimiter_space);
    }

    std::vector<std::string> rsplit(const std::string_view str, const std::string_view delimiter,
                                    const std::size_t max_split, const StringSplitOptions options) noexcept
    {
        return rsplit_impl(str, delimiter, max_split, options, rfind_delimiter);
    }
}
