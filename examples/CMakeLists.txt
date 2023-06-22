cmake_minimum_required(VERSION 3.21...3.26)

#-------------------------------------------------------------------------------
# Project Definition
#-------------------------------------------------------------------------------

project(        "StringPy Examples"
  VERSION       "1.0.0"
  DESCRIPTION   "Examples of using the stringpy library"
  HOMEPAGE_URL  "https://github.com/hun1er/stringpy"
  LANGUAGES     "CXX"
)

#-------------------------------------------------------------------------------
# Options
#-------------------------------------------------------------------------------

option(STRINGPY_EXAMPLES_USE_LINKER_GOLD "Use the Gold linker instead of the default linker when compiling with GCC." OFF)
option(STRINGPY_EXAMPLES_USE_LINKER_LLD "Use the LLD linker instead of the default linker when compiling with Clang." OFF)
option(STRINGPY_EXAMPLES_ENABLE_CLANG_TIDY "Enable static analysis with Clang-Tidy to detect code issues." OFF)
option(STRINGPY_EXAMPLES_ENABLE_CPPCHECK "Enable static analysis with Cppcheck to detect code issues." OFF)
option(STRINGPY_EXAMPLES_ENABLE_PVS_STUDIO "Enable static analysis with PVS-Studio to detect code issues." OFF)
option(STRINGPY_EXAMPLES_ENABLE_IWYU "Enable Include What You Use tool to optimize header usage." OFF)

#-------------------------------------------------------------------------------
# Variable Definitions
#-------------------------------------------------------------------------------

string(TOLOWER "${PROJECT_NAME}" PNAME_LOWER)
string(TOUPPER "${PROJECT_NAME}" PNAME_UPPER)
string(REGEX REPLACE "[ \n\r\t]+" "_" PNAME_LOWER "${PNAME_LOWER}")
string(REGEX REPLACE "[ \n\r\t]+" "_" PNAME_UPPER "${PNAME_UPPER}")

#-------------------------------------------------------------------------------
# Include Modules
#-------------------------------------------------------------------------------

include("cmake/Iwyu.cmake")
include("cmake/Cppcheck.cmake")
include("cmake/ClangTidy.cmake")
include("cmake/PvsStudio.cmake")
include("cmake/CompileOptions.cmake")

#-------------------------------------------------------------------------------
# Link Libraries
#-------------------------------------------------------------------------------

link_libraries("StringPy::stringpy")

#-------------------------------------------------------------------------------
# Executable Definitions
#-------------------------------------------------------------------------------

add_executable("example_capitalize" "src/capitalize.cpp")
add_executable("example_center"     "src/center.cpp")
add_executable("example_count"      "src/count.cpp")
add_executable("example_ctype"      "src/ctype.cpp")
add_executable("example_endswith"   "src/endswith.cpp")
add_executable("example_equal"      "src/equal.cpp")
add_executable("example_expandtabs" "src/expandtabs.cpp")
add_executable("example_find"       "src/find.cpp")
add_executable("example_format"     "src/format.cpp")
add_executable("example_join"       "src/join.cpp")
add_executable("example_just"       "src/just.cpp")
add_executable("example_partition"  "src/partition.cpp")
add_executable("example_replace"    "src/replace.cpp")
add_executable("example_split"      "src/split.cpp")
add_executable("example_splitlines" "src/splitlines.cpp")
add_executable("example_startswith" "src/startswith.cpp")
add_executable("example_strip"      "src/strip.cpp")
add_executable("example_stype"      "src/stype.cpp")
add_executable("example_swapcase"   "src/swapcase.cpp")
add_executable("example_title"      "src/title.cpp")
add_executable("example_translate"  "src/translate.cpp")

# Get a list of targets in the current directory
get_property(TARGET_LIST
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  PROPERTY "BUILDSYSTEM_TARGETS"
)

# Group all targets in the current directory into one target
add_custom_target("examples")
add_dependencies("examples" ${TARGET_LIST})

#-------------------------------------------------------------------------------
# Static analysis
#-------------------------------------------------------------------------------

if(${PNAME_UPPER}_ENABLE_CLANG_TIDY)
  # Enable Clang-Tidy for "stringpy" and all other targets in the current directory
  enable_clang_tidy(TARGETS "stringpy" ${TARGET_LIST})
endif()

if(${PNAME_UPPER}_ENABLE_CPPCHECK)
  # Enable Cppcheck for "stringpy" and all other targets in the current directory
  enable_cppcheck(TARGETS "stringpy" ${TARGET_LIST})
endif()

if(${PNAME_UPPER}_ENABLE_PVS_STUDIO)
  # Enable PVS-Studio for "stringpy" and all other targets in the current directory
  enable_pvs_studio(TARGETS "stringpy" ${TARGET_LIST})
endif()

if(${PNAME_UPPER}_ENABLE_IWYU)
  # Enable Include What You Use for "stringpy" and all other targets in the current directory
  enable_iwyu(TARGETS "stringpy" ${TARGET_LIST})
endif()

#-------------------------------------------------------------------------------
# Code Formatting
#-------------------------------------------------------------------------------

if(PROJECT_IS_TOP_LEVEL)
  # Run Clang-Format on the source files of a target before building it.
  format_target_sources(TARGETS ${TARGET_LIST})
endif()
