/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/translate.hpp"
#include <cstddef>
#include <utility>

namespace strpy
{
    TransMap make_trans(const std::string_view from, const std::string_view to,
                        const std::string_view delete_chars) noexcept
    {
        TransMap trans_map{};
        const auto from_size = from.size();

        for (std::size_t i = 0; i < from_size; ++i) {
            trans_map[from[i]] = to[i];
        }

        for (const auto ch : delete_chars) {
            trans_map[ch] = EOS;
        }

        return trans_map;
    }

    std::string translate(const std::string_view str, const TransMap& trans_map) noexcept
    {
        if (str.empty()) {
            return {};
        }

        if (trans_map.empty()) {
            return std::string{str};
        }

        std::string result{};
        result.reserve(str.size());
        const auto& end = trans_map.end();

        for (const auto ch : str) {
            const auto& it = trans_map.find(ch);

            if (it == end) {
                result += ch;
            }
            else if (it->second != EOS) {
                result += it->second;
            }
        }

        return result;
    }
}
