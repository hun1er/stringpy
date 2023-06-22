/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/format.hpp"
#include <cstddef>

namespace
{
    /** @brief The average size of an argument in the format function. */
    constexpr std::size_t AVERAGE_ARG_SIZE = 6;

    /** @brief The size of the placeholder in the format function. */
    constexpr std::size_t PLACEHOLDER_SIZE = 2;
}

namespace strpy
{
    std::string format(const std::string_view str, const std::initializer_list<std::string>& args)
    {
        std::string result{str};
        result.reserve(str.size() + (args.size() * AVERAGE_ARG_SIZE));
        std::size_t pos = 0;

        for (const auto& arg : args) {
            if (pos = result.find("{}", pos); std::string::npos == pos) {
                break;
            }

            result.replace(pos, PLACEHOLDER_SIZE, arg);
            pos += arg.size();
        }

        return result;
    }
}
