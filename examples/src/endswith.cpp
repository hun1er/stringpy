/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/endswith.hpp"
#include <iostream>

namespace
{
    void example1()
    {
        constexpr std::string_view url{"https://example.com/path?param=value"};
        const auto result = strpy::ends_with(url, "value");

        std::cout << "URL: " << url << '\n';
        std::cout << "Does the URL end with 'value'? " << std::boolalpha << result << '\n';
    }

    void example2()
    {
        constexpr std::string_view str{"This is an example string."};
        constexpr std::size_t start = 5;
        constexpr std::size_t end = 10;
        const auto result = strpy::ends_with(str, "an", start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring (start " << start << " end " << end << "): " << str.substr(start, end - start) << '\n';
        std::cout << "Does the substring 'is an' end with 'an'? " << std::boolalpha << result << '\n';
    }

    void example3()
    {
        constexpr std::string_view filename{"image.JpG"};
        const auto result = strpy::ends_with_icase(filename, ".jpg");

        std::cout << "Filename: " << filename << '\n';
        std::cout << "Is the file a JPEG image? " << std::boolalpha << result;
        std::cout << "\nSuffix checked: '.jpg'" << '\n';
    }

    void example4()
    {
        constexpr std::string_view str{"This is an EXAMPLE string."};
        constexpr std::size_t start = 11;
        constexpr std::size_t end = 18;
        const auto result = strpy::ends_with_icase(str, "example", start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring (start " << start << " end " << end << "): " << str.substr(start, end - start) << '\n';
        std::cout << "Does the substring 'EXAMPLE' end with 'example'? " << std::boolalpha << result << '\n';
    }
}

int main()
{
    std::cout << "Example 1 (ends_with)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (ends_with)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (ends_with_icase)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (ends_with_icase)" << '\n';
    example4();

    return 0;
}

// Program output:
//
// Example 1 (ends_with)
// URL: https://example.com/path?param=value
// Does the URL end with 'value'? true
//
// Example 2 (ends_with)
// String: This is an example string.
// Substring (start 5 end 10): is an
// Does the substring 'is an' end with 'an'? true
//
// Example 3 (ends_with_icase)
// Filename: image.JpG
// Is the file a JPEG image? true
// Suffix checked: '.jpg'
//
// Example 4 (ends_with_icase)
// String: This is an EXAMPLE string.
// Substring (start 11 end 18): EXAMPLE
// Does the substring 'EXAMPLE' end with 'example'? true
