/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/capitalize.hpp"
#include <iostream>

int main()
{
    constexpr std::string_view sentence{"tHe qUiCk bRoWn fOx jUmPs oVeR tHe lAzY dOg."};
    const auto& result = strpy::capitalize(sentence);

    std::cout << "Original sentence: " << sentence << '\n';
    std::cout << "Capitalized sentence: " << result << '\n';

    return 0;
}

// Program output:
//
// Original sentence: tHe qUiCk bRoWn fOx jUmPs oVeR tHe lAzY dOg.
// Capitalized sentence: The quick brown fox jumps over the lazy dog.
