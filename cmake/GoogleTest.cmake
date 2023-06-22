include(GoogleTest)

# GoogleTest - Google Testing and Mocking Framework
FetchContent_Declare(
  GoogleTest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)

# Fetches GTest from the repository if it is not found on the system.
#
# First checks if GTest is already installed on the system.
# If GTest is not found on the system, calls FetchContent_MakeAvailable(GoogleTest)
# to fetch GTest from the repository and make it available for use.
function(fetch_gtest)
  find_package(GTest)

  if(NOT GTest_FOUND)
    FetchContent_MakeAvailable(GoogleTest)
  endif()
endfunction()
