/*
 * SPDX-FileCopyrightText: 2023 the_hunter
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Provides functions for formatting strings.
 *
 * @example format.cpp
 * Demonstrates the use of the format() and to_string() functions from the strpy namespace.
 */

#pragma once

#include "stringpy/const.hpp"
#include "stringpy/export.hpp"
#include "stringpy/strip.hpp"
#include <initializer_list>
#include <string_view>
#include <type_traits>
#include <sstream>
#include <string>
#include <utility>

namespace strpy::detail
{
    template <typename T>
    struct IsChar : std::false_type
    {
    };

    template <>
    struct IsChar<std::string::value_type> : std::true_type
    {
    };

    template <>
    struct IsChar<std::make_signed_t<std::string::value_type>> : std::true_type
    {
    };

    template <>
    struct IsChar<std::make_unsigned_t<std::string::value_type>> : std::true_type
    {
    };

    template <typename T>
    struct IsToStringable : std::false_type
    {
    };

    template <>
    struct IsToStringable<char> : std::true_type
    {
    };

    template <>
    struct IsToStringable<signed char> : std::true_type
    {
    };

    template <>
    struct IsToStringable<unsigned char> : std::true_type
    {
    };

    template <>
    struct IsToStringable<double> : std::true_type
    {
    };

    template <>
    struct IsToStringable<float> : std::true_type
    {
    };

    template <>
    struct IsToStringable<int> : std::true_type
    {
    };

    template <>
    struct IsToStringable<long> : std::true_type // NOLINT(google-runtime-int) //-V126
    {
    };

    template <>
    struct IsToStringable<long double> : std::true_type
    {
    };

    template <>
    struct IsToStringable<long long> : std::true_type // NOLINT(google-runtime-int)
    {
    };

    template <>
    struct IsToStringable<short> : std::true_type // NOLINT(google-runtime-int)
    {
    };

    template <>
    struct IsToStringable<unsigned int> : std::true_type
    {
    };

    template <>
    struct IsToStringable<unsigned long> : std::true_type //-V126 // NOLINT(google-runtime-int)
    {
    };

    template <>
    struct IsToStringable<unsigned long long> : std::true_type // NOLINT(google-runtime-int)
    {
    };

    template <>
    struct IsToStringable<unsigned short> : std::true_type // NOLINT(google-runtime-int)
    {
    };

    /**
     * @brief A constant that checks if a type is a character type.
     *
     * This constant is \c true if the given type is a character type, and \c false otherwise.
     *
     * @tparam T The type to check.
     * @private
     */
    template <typename T>
    inline constexpr bool IS_CHAR = IsChar<T>::value;

    /**
     * @brief A constant that checks if a type can be converted to a string.
     *
     * This constant is \c true if the given type can be converted to a string
     * using the \c std::to_string function, and \c false otherwise.
     *
     * @tparam T The type to check.
     * @private
     */
    template <typename T>
    inline constexpr bool IS_TO_STRINGABLE = IsToStringable<T>::value;
}

namespace strpy
{
    /**
     * @brief Converts a value of type T to a string.
     *
     * @tparam T The type of the value to be converted.
     *
     * @param value The value to be converted.
     *
     * @return A string representation of the value.
     */
    template <typename T>
    [[nodiscard]] std::string to_string(T&& value)
    {
        using DecayedType = std::decay_t<T>;
        using CharType = std::string::value_type;

        if constexpr (std::is_same_v<DecayedType, CharType*> || std::is_null_pointer_v<DecayedType>) {
            return nullptr == value ? std::string{EMPTY_STR} : std::string{value};
        }
        else if constexpr (std::is_same_v<DecayedType, CharType> || std::is_convertible_v<DecayedType, std::string>) {
            return std::string{value};
        }
        else if constexpr (detail::IS_CHAR<DecayedType>) {
            return std::string{static_cast<CharType>(value)};
        }
        else if constexpr (detail::IS_TO_STRINGABLE<DecayedType>) {
            if constexpr (std::is_floating_point_v<DecayedType>) {
                return rstrip<std::string>(std::to_string(std::forward<T>(value)), ".0");
            }
            else {
                return std::to_string(std::forward<T>(value));
            }
        }
        else {
            std::ostringstream stream{}; // NOLINT(misc-const-correctness)
            stream << std::forward<T>(value);
            return stream.str();
        }
    }

    /**
     * @brief Converts a boolean value to a string.
     *
     * @param value The boolean value to be converted.
     *
     * @return A string representation of the boolean value (<tt>"true"</tt> or <tt>"false"</tt>).
     */
    [[nodiscard]] inline std::string to_string(const bool value) noexcept
    {
        return value ? std::string{"true"} : std::string{"false"};
    }

    /**
     * @brief Converts a \c std::string_view to a string.
     *
     * @param value The value to be converted.
     *
     * @return A string representation of the value.
     */
    [[nodiscard]] inline std::string to_string(const std::string_view value) noexcept
    {
        return std::string{value};
    }

    /**
     * @brief Converts an initializer list of characters to a string.
     *
     * @param value The value to be converted.
     *
     * @return A string representation of the value.
     */
    [[nodiscard]] inline std::string to_string(const std::initializer_list<std::string::value_type>& value) noexcept
    {
        return std::string{value};
    }

    /**
     * @brief Converts a value to a string with formatting flags.
     *
     * The value of any type is forwarded to a \c std::ostringstream
     * with the specified formatting flags to produce a string representation of the value.
     *
     * @tparam T The type of the value to convert.
     *
     * @param value The value to convert to a string.
     * @param format_flags The formatting flags to use when converting the value to a string.
     *
     * @return A string representation of the value with the specified formatting.
     */
    template <typename T>
    [[nodiscard]] std::string to_string(T&& value, const std::ios_base::fmtflags format_flags)
    {
        std::ostringstream stream{};
        stream.flags(format_flags);
        stream << std::forward<T>(value);

        return stream.str();
    }

    /**
     * @brief Formats a string by replacing placeholders with the given arguments.
     *
     * The function uses <tt>"{}"</tt> as a placeholder to specify where the arguments
     * should be inserted in the string to produce a formatted string.
     *
     * @param str The string containing placeholders to be replaced.
     * @param args The arguments to be inserted into the string.
     *
     * @return A formatted string with placeholders replaced by the given arguments.
     */
    [[nodiscard]] STRINGPY_EXPORT std::string format(std::string_view str,
                                                     const std::initializer_list<std::string>& args);

    /**
     * @brief Formats a string by replacing placeholders with the given arguments.
     *
     * The function uses <tt>"{}"</tt> as a placeholder to specify where the arguments
     * should be inserted in the string to produce a formatted string.
     *
     * @tparam Args The types of the arguments to be inserted into the string.
     *
     * @param str The string containing placeholders to be replaced.
     * @param args The arguments to be inserted into the string.
     *
     * @return A formatted string with placeholders replaced by the given arguments.
     */
    template <typename... Args>
    [[nodiscard]] std::string format(const std::string_view str, Args&&... args)
    {
        return format(str, {to_string(std::forward<Args>(args))...});
    }
}
