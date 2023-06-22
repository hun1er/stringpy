/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

#include "stringpy/find.hpp"
#include <iostream>
#include <string>

namespace
{
    void example1()
    {
        constexpr std::string_view str{"The quick brown fox jumps over the lazy dog."};
        constexpr std::string_view sub{"fox"};
        const auto result = strpy::find(str, sub);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring: " << sub << '\n';

        if (result != std::string::npos) {
            std::cout << "Found substring at position: " << result << '\n';
        }
        else {
            std::cout << "Substring not found" << '\n';
        }
    }

    void example2()
    {
        constexpr std::string_view str{"tHE QuiCK bROwN fOx jUmPs OvER tHe lAZY DOg."};
        constexpr std::string_view sub{"FOX"};
        constexpr std::size_t start = 10;
        constexpr std::size_t end = 20;
        const auto result = strpy::find_icase(str, sub, start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring: " << sub << '\n';

        if (result != std::string::npos) {
            std::cout << "Found substring at position: " << result << '\n';
        }
        else {
            std::cout << "Substring not found" << '\n';
        }
    }

    void example3()
    {
        constexpr std::string_view str{"Mi casa, su casa."};
        constexpr std::string_view sub{"casa"};
        constexpr std::size_t start = 0;
        constexpr std::size_t end = 20;
        const auto result = strpy::rfind(str, sub, start, end);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring: " << sub << '\n';

        if (result != std::string::npos) {
            std::cout << "Found substring at position: " << result << '\n';
        }
        else {
            std::cout << "Substring not found" << '\n';
        }
    }

    void example4()
    {
        constexpr std::string_view str{"MI Casa, SU CAsa."};
        constexpr std::string_view sub{"casa"};
        const auto result = strpy::rfind_icase(str, sub);

        std::cout << "String: " << str << '\n';
        std::cout << "Substring: " << sub << '\n';

        if (result != std::string::npos) {
            std::cout << "Found substring at position: " << result << '\n';
        }
        else {
            std::cout << "Substring not found" << '\n';
        }
    }

    void example5()
    {
        constexpr std::string_view str{"abc123"};
        constexpr std::string_view digits{"0123456789"};
        const auto result = strpy::find_first_of(str, digits);

        std::cout << "String: " << str << '\n';
        std::cout << "Digits: " << digits << '\n';

        if (result != std::string::npos) {
            std::cout << "The first digit is at position " << result << '\n';
        }
        else {
            std::cout << "No digits found" << '\n';
        }
    }

    void example6()
    {
        constexpr std::string_view str = "sTrINg";
        constexpr std::string_view vowels = "aeiou";
        const auto result = strpy::find_first_of_icase(str, vowels);

        std::cout << "String: " << str << '\n';
        std::cout << "Vowels: " << vowels << '\n';

        if (result != std::string::npos) {
            std::cout << "The first vowel is at position " << result << '\n';
        }
        else {
            std::cout << "No vowels found" << '\n';
        }
    }

    void example7()
    {
        constexpr std::string_view str{"123abc"};
        constexpr std::string_view digits{"0123456789"};
        const auto result = strpy::find_first_not_of(str, digits);

        std::cout << "String: " << str << '\n';
        std::cout << "Digits: " << digits << '\n';

        if (result != std::string::npos) {
            std::cout << "The first non-digit is at position " << result << '\n';
        }
        else {
            std::cout << "No non-digits found" << '\n';
        }
    }

    void example8()
    {
        constexpr std::string_view str{"EXAmplE"};
        constexpr std::string_view vowels{"aeiou"};
        const auto result = strpy::find_first_not_of_icase(str, vowels);

        std::cout << "String: " << str << '\n';
        std::cout << "Vowels: " << vowels << '\n';

        if (result != std::string::npos) {
            std::cout << "The first non-vowel is at position " << result << '\n';
        }
        else {
            std::cout << "No non-vowels found" << '\n';
        }
    }

    void example9()
    {
        constexpr std::string_view str = "Hello, World!";
        constexpr std::string_view punctuations = ",.!?;:";
        const auto result = strpy::find_last_of(str, punctuations);

        std::cout << "String: " << str << '\n';
        std::cout << "Punctuations: " << punctuations << '\n';

        if (result != std::string::npos) {
            std::cout << "The last punctuation mark is at position " << result << '\n';
        }
        else {
            std::cout << "No punctuation marks found" << '\n';
        }
    }

    void example10()
    {
        constexpr std::string_view str = "exaMpLE";
        constexpr std::string_view vowels = "aeiou";
        const auto result = strpy::find_last_of_icase(str, vowels);

        std::cout << "String: " << str << '\n';
        std::cout << "Vowels: " << vowels << '\n';

        if (result != std::string::npos) {
            std::cout << "The last vowel is at position " << result << '\n';
        }
        else {
            std::cout << "No vowels found" << '\n';
        }
    }

    void example11()
    {
        constexpr std::string_view str = "Hello, World!";
        constexpr std::string_view punctuations = ",.!?;:";
        const auto result = strpy::find_last_not_of(str, punctuations);

        std::cout << "String: " << str << '\n';
        std::cout << "Punctuations: " << punctuations << '\n';

        if (result != std::string::npos) {
            std::cout << "The last character that is not a punctuation mark is at position " << result << '\n';
        }
        else {
            std::cout << "No characters that are not punctuation marks found" << '\n';
        }
    }

    void example12()
    {
        constexpr std::string_view str = "exaMpLE";
        constexpr std::string_view vowels = "aeiou";
        const auto result = strpy::find_last_not_of_icase(str, vowels);

        std::cout << "String: " << str << '\n';
        std::cout << "Vowels: " << vowels << '\n';

        if (result != std::string::npos) {
            std::cout << "The last non-vowel is at position " << result << '\n';
        }
        else {
            std::cout << "No non-vowels found" << '\n';
        }
    }
}

int main()
{
    std::cout << "Example 1 (find)" << '\n';
    example1();
    std::cout << '\n';

    std::cout << "Example 2 (find_icase)" << '\n';
    example2();
    std::cout << '\n';

    std::cout << "Example 3 (rfind)" << '\n';
    example3();
    std::cout << '\n';

    std::cout << "Example 4 (rfind_icase)" << '\n';
    example4();
    std::cout << '\n';

    std::cout << "Example 5 (find_first_of)" << '\n';
    example5();
    std::cout << '\n';

    std::cout << "Example 6 (find_first_of_icase)" << '\n';
    example6();
    std::cout << '\n';

    std::cout << "Example 7 (find_first_not_of)" << '\n';
    example7();
    std::cout << '\n';

    std::cout << "Example 8 (find_first_not_of_icase)" << '\n';
    example8();
    std::cout << '\n';

    std::cout << "Example 9 (find_last_of)" << '\n';
    example9();
    std::cout << '\n';

    std::cout << "Example 10 (find_last_of_icase)" << '\n';
    example10();
    std::cout << '\n';

    std::cout << "Example 11 (find_last_not_of)" << '\n';
    example11();
    std::cout << '\n';

    std::cout << "Example 12 (find_last_not_of_icase)" << '\n';
    example12();

    return 0;
}

// Program output:
//
// Example 1 (find)
// String: The quick brown fox jumps over the lazy dog.
// Substring: fox
// Found substring at position: 16
//
// Example 2 (find_icase)
// String: tHE QuiCK bROwN fOx jUmPs OvER tHe lAZY DOg.
// Substring: FOX
// Found substring at position: 16
//
// Example 3 (rfind)
// String: Mi casa, su casa.
// Substring: casa
// Found substring at position: 12
//
// Example 4 (rfind_icase)
// String: MI Casa, SU CAsa.
// Substring: casa
// Found substring at position: 12
//
// Example 5 (find_first_of)
// String: abc123
// Digits: 0123456789
// The first digit is at position 3
//
// Example 6 (find_first_of_icase)
// String: sTrINg
// Vowels: aeiou
// The first vowel is at position 3
//
// Example 7 (find_first_not_of)
// String: 123abc
// Digits: 0123456789
// The first non-digit is at position 3
//
// Example 8 (find_first_not_of_icase)
// String: EXAmplE
// Vowels: aeiou
// The first non-vowel is at position 1
//
// Example 9 (find_last_of)
// String: Hello, World!
// Punctuations: ,.!?;:
// The last punctuation mark is at position 12
//
// Example 10 (find_last_of_icase)
// String: exaMpLE
// Vowels: aeiou
// The last vowel is at position 6
//
// Example 11 (find_last_not_of)
// String: Hello, World!
// Punctuations: ,.!?;:
// The last character that is not a punctuation mark is at position 11
//
// Example 12 (find_last_not_of_icase)
// String: exaMpLE
// Vowels: aeiou
// The last non-vowel is at position 5
