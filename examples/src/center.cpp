/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/center.hpp"
#include <iostream>

int main()
{
    constexpr std::string_view str{"Hello, World!"};
    constexpr std::size_t width = 21;
    constexpr auto fill_char = '*';
    const auto& result = strpy::center(str, width, fill_char);

    std::cout << "String: " << str << '\n';
    std::cout << "Width: " << width << '\n';
    std::cout << "Fill character: '" << fill_char << "'" << '\n';
    std::cout << "Centered string: " << result << '\n';

    return 0;
}

// Program output:
//
// String: Hello, World!
// Width: 21
// Fill character: '*'
// Centered string: ****Hello, World!****
