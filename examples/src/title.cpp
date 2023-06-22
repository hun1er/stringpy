/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/title.hpp"
#include <iostream>

int main()
{
    constexpr std::string_view str{"hello, world!"};
    const auto& result = strpy::title(str);

    std::cout << "Original string: '" << str << "'\n";
    std::cout << "Titled string: '" << result << "'\n";

    return 0;
}

// Program output:
//
// Original string: 'hello, world!'
// Titled string: 'Hello, World!'
