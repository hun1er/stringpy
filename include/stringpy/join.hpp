/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides a function for joining the elements of a container into a string using a delimiter.
 *
 * @example join.cpp
 * Demonstrates the use of the join() function from the strpy namespace.
 */

#pragma once

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace strpy
{
    /**
     * @brief Joins the elements of a container into a string using a delimiter.
     *
     * Takes a container of elements and a delimiter string as arguments and returns a new string
     * that is the concatenation of the elements in the container with the delimiter between them.
     *
     * @tparam Container The type of the container to join.
     * @tparam ValueType The type of the values in the container (optional).
     *
     * @param container The container to join.
     * @param delimiter The delimiter to use between elements.
     *
     * @return A new string that is the concatenation of the elements in the container with the delimiter between them.
     *
     * @sa https://www.w3schools.com/python/ref_string_join.asp
     */
    template <typename Container, typename ValueType = typename Container::value_type>
    [[nodiscard]] std::string join(const Container& container, const std::string& delimiter)
    {
        auto first = std::begin(container);
        auto last = std::end(container);

        if (first == last) {
            return {};
        }

        std::ostringstream result_stream{};
        result_stream.rdbuf()->pubsetbuf(nullptr, std::distance(first, last));
        std::copy(first, std::prev(last), std::ostream_iterator<ValueType>(result_stream, delimiter.c_str()));
        first = std::prev(last);

        if (first != last) {
            result_stream << *first;
        }

        return result_stream.rdbuf()->str();
    }
}
