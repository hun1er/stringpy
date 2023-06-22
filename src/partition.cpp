/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/partition.hpp"
#include "stringpy/const.hpp"
#include "stringpy/find.hpp"

namespace
{
    /** @brief Type alias for a function pointer to strpy::find or strpy::find_icase */
    using FindFunc = decltype(&strpy::find);

    std::tuple<std::string, std::string, std::string>
      partition_impl(const std::string_view str, const std::string_view sep, const FindFunc find) noexcept
    {
        const auto pos = find(str, sep, 0, std::string_view::npos);

        if (std::string_view::npos == pos) {
            return {std::string{str}, strpy::EMPTY_STR, strpy::EMPTY_STR};
        }

        return {std::string{str.substr(0, pos)}, std::string{str.substr(pos, sep.length())},
                std::string{str.substr(pos + sep.size())}};
    }

    /** @brief Type alias for a function pointer to strpy::rfind or strpy::rfind_icase */
    using RFindFunc = decltype(&strpy::rfind);

    std::tuple<std::string, std::string, std::string>
      rpartition_impl(const std::string_view str, const std::string_view sep, const RFindFunc rfind) noexcept
    {
        const auto pos = rfind(str, sep, 0, std::string_view::npos);

        if (pos == std::string_view::npos) {
            return {strpy::EMPTY_STR, strpy::EMPTY_STR, std::string{str}};
        }

        return {std::string{str.substr(0, pos)}, std::string{str.substr(pos, sep.length())},
                std::string{str.substr(pos + sep.size())}};
    }
}

namespace strpy
{
    std::tuple<std::string, std::string, std::string> partition(const std::string_view str,
                                                                const std::string_view sep) noexcept
    {
        return partition_impl(str, sep, find);
    }

    std::tuple<std::string, std::string, std::string> partition_icase(const std::string_view str,
                                                                      const std::string_view sep) noexcept
    {
        return partition_impl(str, sep, find_icase);
    }

    std::tuple<std::string, std::string, std::string> rpartition(const std::string_view str,
                                                                 const std::string_view sep) noexcept
    {
        return rpartition_impl(str, sep, rfind);
    }

    std::tuple<std::string, std::string, std::string> rpartition_icase(const std::string_view str,
                                                                       const std::string_view sep) noexcept
    {
        return rpartition_impl(str, sep, rfind_icase);
    }
}
