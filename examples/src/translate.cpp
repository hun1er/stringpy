/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/translate.hpp"
#include <iostream>
#include <iterator>
#include <utility>

namespace
{
    void print_translation_map(const strpy::TransMap& trans_map)
    {
        std::cout << "Translation map: ";
        const auto& end = trans_map.end();

        for (auto it = trans_map.begin(); it != end; ++it) {
            std::cout << "'" << it->first << "'"
                      << " -> "
                      << "'" << it->second << "'";

            if (std::next(it) != trans_map.end()) {
                std::cout << ", ";
            }
        }
    }
}

namespace
{
    void example1()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "Original string: '" << str << "'\n";

        const auto& trans_map = strpy::make_trans("h", "H");
        print_translation_map(trans_map);
        std::cout << '\n';

        const auto& result = strpy::translate(str, trans_map);
        std::cout << "Translated string: '" << result << "'\n";
    }

    void example2()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "Original string: '" << str << "'\n";

        const auto& trans_map = strpy::make_trans("helo", "HELO");
        print_translation_map(trans_map);
        std::cout << '\n';

        const auto& result = strpy::translate(str, trans_map);
        std::cout << "Translated string: '" << result << "'\n";
    }

    void example3()
    {
        constexpr std::string_view str{"hello, world!"};
        std::cout << "Original string: '" << str << "'\n";

        const auto& trans_map = strpy::make_trans("", "", "l");
        print_translation_map(trans_map);
        std::cout << '\n';

        const auto& result = strpy::translate(str, trans_map);
        std::cout << "Translated string: '" << result << "'\n";
    }
}

int main()
{
    std::cout << "Example 1 (translate with single character replacement)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (translate with multiple character replacement)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (translate with character deletion)" << '\n';
    example3();

    return 0;
}

// Program output:
//
// Example 1 (translate with single character replacement)
// Original string: 'hello, world!'
// Translation map: 'h' -> 'H'
// Translated string: 'Hello, world!'
//
// Example 2 (translate with multiple character replacement)
// Original string: 'hello, world!'
// Translation map: 'o' -> 'O', 'l' -> 'L', 'e' -> 'E', 'h' -> 'H'
// Translated string: 'HELLO, wOrLd!'
//
// Example 3 (translate with character deletion)
// Original string: 'hello, world!'
// Translation map: 'l' -> ''
// Translated string: 'heo, word!'
