/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/expandtabs.hpp"
#include <iostream>

int main()
{
    constexpr std::string_view str{"Name:\tAlice\nAge:\t30"};
    constexpr std::size_t tabsize = 12;
    const auto& result = strpy::expand_tabs(str, tabsize);

    std::cout << "String: \n" << str << '\n';
    std::cout << "Tab size: " << tabsize << '\n';
    std::cout << "Expanded string: \n" << result << '\n';

    return 0;
}

// Program output:
//
// String:
// Name:   Alice
// Age:    30
// Tab size: 12
// Expanded string:
// Name:       Alice
// Age:        30
