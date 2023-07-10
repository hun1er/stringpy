cmake_minimum_required(VERSION 3.21...3.26)

#-------------------------------------------------------------------------------
# Project Definition
#-------------------------------------------------------------------------------

project(        "StringPy"
  VERSION       "1.0.2"
  DESCRIPTION   "A C++17 library providing a set of string manipulation functions, many of which are similar to Python string methods."
  HOMEPAGE_URL  "https://github.com/hun1er/stringpy"
  LANGUAGES     "CXX"
)

#-------------------------------------------------------------------------------
# Options
#-------------------------------------------------------------------------------

# STRINGPY_SHARED_LIBS option (undefined by default) can be used to force shared/static build.
option(STRINGPY_INSTALL         "Generate install target."                              ${PROJECT_IS_TOP_LEVEL})
option(STRINGPY_BUILD_DOCS      "Generate documentation."                               ${PROJECT_IS_TOP_LEVEL})
option(STRINGPY_BUILD_EXAMPLES  "Build usage examples."                                 ${PROJECT_IS_TOP_LEVEL})
option(STRINGPY_BUILD_TESTS     "Build unit tests."                                     ${PROJECT_IS_TOP_LEVEL})
option(STRINGPY_CODE_COVERAGE   "Generate a coverage target using LCOV and genhtml."    ${PROJECT_IS_TOP_LEVEL})
option(STRINGPY_SYSTEM_HEADERS  "Treat headers as system headers to suppress warnings." ON)

if(DEFINED STRINGPY_SHARED_LIBS)
  # The parent scope will not be affected
  set(BUILD_SHARED_LIBS ${STRINGPY_SHARED_LIBS})
endif()

#-------------------------------------------------------------------------------
# Variable Definitions
#-------------------------------------------------------------------------------

string(TOLOWER "${PROJECT_NAME}" PNAME_LOWER)
string(TOUPPER "${PROJECT_NAME}" PNAME_UPPER)
string(REGEX REPLACE "[ \n\r\t]+" "_" PNAME_LOWER "${PNAME_LOWER}")
string(REGEX REPLACE "[ \n\r\t]+" "_" PNAME_UPPER "${PNAME_UPPER}")
string(REGEX REPLACE "[ \n\r\t]+" "_" PNAME_NO_SPACES "${PROJECT_NAME}")
string(SUBSTRING "${PNAME_UPPER}" 0 1 PNAME_FIRST_LETTER)
string(REGEX REPLACE "^.(.*)" "${PNAME_FIRST_LETTER}\\1" PNAME_CAPITALIZED "${PNAME_NO_SPACES}")

if(${PNAME_UPPER}_SYSTEM_HEADERS)
  set(${PNAME_UPPER}_SYSTEM_HEADERS_ATTRIBUTE "SYSTEM")
else()
  set(${PNAME_UPPER}_SYSTEM_HEADERS_ATTRIBUTE "")
endif()

include(ProcessorCount)
ProcessorCount(PROCESSOR_CORES)

if(PROCESSOR_CORES EQUAL 0)
  set(PROCESSOR_CORES 2)
endif()

if(PROCESSOR_CORES GREATER 4)
  set(PROCESSOR_CORES 4)
endif()

#-------------------------------------------------------------------------------
# Include Modules
#-------------------------------------------------------------------------------

include(FetchContent)
include(GenerateExportHeader)
include("cmake/Install.cmake")
include("cmake/Doxygen.cmake")
include("cmake/Coverage.cmake")
include("cmake/GoogleTest.cmake")
include("cmake/ClangFormat.cmake")

#-------------------------------------------------------------------------------
# Library Definition
#-------------------------------------------------------------------------------

add_library("${PNAME_LOWER}")
add_library("${PNAME_CAPITALIZED}::${PNAME_LOWER}" ALIAS "${PNAME_LOWER}")

# Generate the export header file
set(EXPORT_HEADER "${PROJECT_BINARY_DIR}/include/${PNAME_LOWER}/export.hpp")
generate_export_header("${PNAME_LOWER}" EXPORT_FILE_NAME "${EXPORT_HEADER}")

set(PUBLIC_HEADERS
  "include/${PNAME_LOWER}/capitalize.hpp"
  "include/${PNAME_LOWER}/center.hpp"
  "include/${PNAME_LOWER}/const.hpp"
  "include/${PNAME_LOWER}/count.hpp"
  "include/${PNAME_LOWER}/ctype.hpp"
  "include/${PNAME_LOWER}/endswith.hpp"
  "include/${PNAME_LOWER}/equal.hpp"
  "include/${PNAME_LOWER}/expandtabs.hpp"
  "include/${PNAME_LOWER}/find.hpp"
  "include/${PNAME_LOWER}/format.hpp"
  "include/${PNAME_LOWER}/join.hpp"
  "include/${PNAME_LOWER}/just.hpp"
  "include/${PNAME_LOWER}/partition.hpp"
  "include/${PNAME_LOWER}/replace.hpp"
  "include/${PNAME_LOWER}/split.hpp"
  "include/${PNAME_LOWER}/splitlines.hpp"
  "include/${PNAME_LOWER}/startswith.hpp"
  "include/${PNAME_LOWER}/stringpy.hpp"
  "include/${PNAME_LOWER}/strip.hpp"
  "include/${PNAME_LOWER}/stype.hpp"
  "include/${PNAME_LOWER}/swapcase.hpp"
  "include/${PNAME_LOWER}/title.hpp"
  "include/${PNAME_LOWER}/translate.hpp"
)

set(SOURCES
  ${PUBLIC_HEADERS}
  "src/capitalize.cpp"
  "src/center.cpp"
  "src/count.cpp"
  "src/endswith.cpp"
  "src/equal.cpp"
  "src/expandtabs.cpp"
  "src/find.cpp"
  "src/format.cpp"
  "src/just.cpp"
  "src/partition.cpp"
  "src/replace.cpp"
  "src/split.cpp"
  "src/splitlines.cpp"
  "src/startswith.cpp"
  "src/stype.cpp"
  "src/swapcase.cpp"
  "src/title.cpp"
  "src/translate.cpp"
)

list(APPEND PUBLIC_HEADERS "${EXPORT_HEADER}")
source_group(TREE "${PROJECT_SOURCE_DIR}" FILES ${SOURCES})
target_sources("${PNAME_LOWER}" PRIVATE "${EXPORT_HEADER}" ${SOURCES})

set_target_properties("${PNAME_LOWER}" PROPERTIES
  PUBLIC_HEADER
    "${PUBLIC_HEADERS}"

  SOVERSION
    "${PROJECT_VERSION_MAJOR}"

  VERSION
    "${PROJECT_VERSION}"
)

target_include_directories("${PNAME_LOWER}" ${${PNAME_UPPER}_SYSTEM_HEADERS_ATTRIBUTE}
  PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_definitions("${PNAME_LOWER}"
  PUBLIC
    "$<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:${PNAME_UPPER}_STATIC_DEFINE>"
)

if(WIN32)
  configure_file("${PNAME_LOWER}.rc.in" "${PROJECT_SOURCE_DIR}/${PNAME_LOWER}.rc" @ONLY)
  target_sources("${PNAME_LOWER}" PRIVATE "${PROJECT_SOURCE_DIR}/${PNAME_LOWER}.rc")
endif()

#-------------------------------------------------------------------------------
# Other Targets
#-------------------------------------------------------------------------------

if(${PNAME_UPPER}_BUILD_DOCS)
  find_package("Doxygen" REQUIRED
    COMPONENTS
      "dot"

    OPTIONAL_COMPONENTS
      "dia"
      "mscgen"
  )

  strpy_use_doxygen_awesome_sidebar_only_theme()
  doxygen_add_docs("${PNAME_LOWER}_docs" "include")
endif()

if(${PNAME_UPPER}_BUILD_EXAMPLES)
  add_subdirectory("examples")
endif()

if(${PNAME_UPPER}_BUILD_TESTS)
  if(${PNAME_UPPER}_CODE_COVERAGE)
    if(PROJECT_IS_TOP_LEVEL)
      set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "The build type is set to Debug" FORCE)
    endif()

    target_link_options("${PNAME_LOWER}" PUBLIC "--coverage")
    target_compile_options("${PNAME_LOWER}" PRIVATE "-O0" "-g" "--coverage")

    add_custom_command(TARGET "${PNAME_LOWER}" PRE_BUILD COMMAND
      find ${CMAKE_BINARY_DIR} -type f
      -name '*.gcda' -exec rm {} +
    )
  endif()

  enable_testing()
  add_subdirectory("tests")
endif()

#-------------------------------------------------------------------------------
# Installation
#-------------------------------------------------------------------------------

if(${PNAME_UPPER}_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
  strpy_generate_install_target()
endif()

#-------------------------------------------------------------------------------
# Code Formatting
#-------------------------------------------------------------------------------

if(PROJECT_IS_TOP_LEVEL)
  # Run Clang-Format on the source files of a target before building it.
  strpy_format_target_sources(TARGETS "${PNAME_LOWER}")
endif()
