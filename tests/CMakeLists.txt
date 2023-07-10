cmake_minimum_required(VERSION 3.21...3.26)

#-------------------------------------------------------------------------------
# Project Definition
#-------------------------------------------------------------------------------

project("${PNAME_LOWER}_tests")

#-------------------------------------------------------------------------------
# Executable Definition
#-------------------------------------------------------------------------------

add_executable("${PROJECT_NAME}"
  "src/capitalize.cpp"
  "src/center.cpp"
  "src/count.cpp"
  "src/ctype.cpp"
  "src/endswith.cpp"
  "src/equal.cpp"
  "src/expandtabs.cpp"
  "src/find.cpp"
  "src/format.cpp"
  "src/join.cpp"
  "src/just.cpp"
  "src/partition.cpp"
  "src/replace.cpp"
  "src/split.cpp"
  "src/splitlines.cpp"
  "src/startswith.cpp"
  "src/strip.cpp"
  "src/stype.cpp"
  "src/swapcase.cpp"
  "src/title.cpp"
  "src/translate.cpp"
)

# Fetch GTest and link it to the test executable
strpy_fetch_gtest()

target_link_libraries("${PROJECT_NAME}"
  PRIVATE
    "${PNAME_CAPITALIZED}::${PNAME_LOWER}"
    "GTest::gtest_main"
)

if(${PNAME_UPPER}_CODE_COVERAGE)
  strpy_generate_coverage_target("${PROJECT_NAME}")
endif()

# Register tests
gtest_discover_tests("${PROJECT_NAME}")
