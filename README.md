<p align="center">
  <img src="https://github.com/hun1er/stringpy/blob/main/data/logo/800x250.png?raw=true" alt="StringPy">
</p>

<h1 align="center">
  📚 A C++17 string manipulation library
</h1>

<div align="center">

  <a href="https://github.com/hun1er/stringpy/releases/latest">![Release](https://img.shields.io/github/v/release/hun1er/stringpy)</a>
  <a href="https://codecov.io/gh/hun1er/stringpy">![codecov](https://codecov.io/gh/hun1er/stringpy/branch/main/graph/badge.svg?token=193KW4WRIM)</a>
  <a href="https://github.com/hun1er/stringpy/blob/main/LICENSE">![License](https://img.shields.io/github/license/hun1er/stringpy)</a>

</div>

Provides a set of string manipulation functions, many of which are similar to Python string methods.

## 🌟 Features

-   **Flexible Comparison Options**: Compare strings using either case-sensitive or case-insensitive matching.

-   **Flexible String Matching**: Find substrings within strings using either case-sensitive or case-insensitive matching.

-   **String Splitting and Joining**: Split strings into substrings based on specified delimiters or join multiple strings together with a specified delimiter.

-   **String Transformation**: Transform strings in various ways, such as capitalizing the first letter of each word, centering text within a specified width, expanding tabs to spaces, justifying text to the left or right, replacing substrings with new values, swapping the case of characters or converting them to uppercase or lowercase, etc.

-   **String Trimming**: Remove leading and trailing whitespace or specific characters from strings.

-   **String Formatting**: Provides a very simple yet fast string formatting function. It's at least two times faster than typical solutions based on std::snprintf, such as [this](https://stackoverflow.com/a/26221725) one (tested with Google Benchmark).
    Additionally, this function is safe and does not throw exceptions, even if passed a nullptr as an argument.

-   **Character and String Classification**: Determine the type of character or string, such as whether it is alphanumeric, alphabetic, ASCII, a digit, graphical, printable, punctuation, whitespace, etc.

And more.

## 💪 Robust and Reliable

Each function has been thoroughly tested with unit tests to ensure its correctness and reliability. Additionally, the functions in this library do not throw exceptions and do not use RTTI (Run-Time Type Information), making them safe and easy to use in any project.

## 🌎 Cross-Platform and Dependency-Free

This library is completely self-contained and does not have any external dependencies (except STL). It can be used on any platform that supports C++17 (Windows, Linux, macOS).

## 💻 Usage

There are several ways to include StringPy in your project, such as adding it as a submodule, manually copying the files, or compiling and installing the library.

However, one of the easiest approaches is to use [CMake FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html). To do this, add the following lines to your CMakeLists.txt file:

```cmake
include(FetchContent)

FetchContent_Declare(
  StringPy
  GIT_REPOSITORY https://github.com/hun1er/stringpy.git
  GIT_TAG        v1.0.1
)

FetchContent_MakeAvailable(StringPy)
```

Then you can use the targets and functions of StringPy in other CMakeLists.txt files in your project. For example:

```cmake
target_link_libraries(my_target PRIVATE StringPy::stringpy)
```

Once you have included StringPy in your project, you can use it by including the header files and calling the desired functions. For example:

```cpp
#include <stringpy/stringpy.hpp>

int main()
{
    std::string str = "hello, world!";
    std::string result = strpy::title(str);
    std::cout << result << std::endl; // prints "Hello, World!"

    return 0;
}
```

## 📖 Documentation and Examples

Comprehensive [documentation](https://stringpy.rf.gd/files.html) for each function, including detailed descriptions, parameter explanations, and practical [examples](https://stringpy.rf.gd/examples.html).

## 💬 Contributions

Contributions are highly appreciated! If you have any ideas for new features, bug fixes, or improvements, please feel free to open an issue or submit a pull request.

## 📜 License

StringPy is released under the [MIT License](https://github.com/hun1er/stringpy/blob/main/LICENSE). You are free to use, modify, and distribute this library in your own projects.
