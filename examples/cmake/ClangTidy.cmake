# Enables Clang-Tidy for a list of targets with the specified options.
#
# @param TARGETS The list of target names to enable Clang-Tidy for.
# @param OPTIONS [optional] The options to pass to Clang-Tidy.
# @param EXTRA_ARGS [optional] The additional arguments to append to the compiler command line.
function(enable_clang_tidy)
  # Parse the arguments passed to the function
  cmake_parse_arguments("CT" "" "" "TARGETS;OPTIONS;EXTRA_ARGS" ${ARGN})

  # If TARGETS is not set, print an error message and stop processing
  if(NOT CT_TARGETS)
    message(FATAL_ERROR "TARGETS is not set.")
  endif()

  # If OPTIONS is not set, set it to an empty string
  if(NOT DEFINED CT_OPTIONS)
    set(CT_OPTIONS "")
  else()
    string(PREPEND CT_OPTIONS ";")
  endif()

  # If EXTRA_ARGS is not set, set it to an empty string
  if(NOT DEFINED CT_EXTRA_ARGS)
    set(CT_EXTRA_ARGS "")
  else()
    # Prepend "-extra-arg=" to each element in EXTRA_ARGS
    list(TRANSFORM CT_EXTRA_ARGS PREPEND "-extra-arg=")
    string(PREPEND CT_EXTRA_ARGS ";")
  endif()

  # Set c_extra_args and cxx_extra_args to EXTRA_ARGS
  set(c_extra_args "${CT_EXTRA_ARGS}")
  set(cxx_extra_args "${CT_EXTRA_ARGS}")

  # If the C compiler is not Clang, add "-extra-arg=-Wno-unknown-warning-option" to c_extra_args
  if(NOT "${CMAKE_C_COMPILER_ID}" STREQUAL "" AND NOT "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    set(c_extra_args
      ";-extra-arg=-Wno-unknown-warning-option;-extra-arg=-Wno-ignored-optimization-argument${CT_EXTRA_ARGS}"
    )
  endif()

  # If the C++ compiler is not Clang, add "-extra-arg=-Wno-unknown-warning-option" to cxx_extra_args
  if(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "" AND NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(cxx_extra_args
      ";-extra-arg=-Wno-unknown-warning-option;-extra-arg=-Wno-ignored-optimization-argument${CT_EXTRA_ARGS}"
    )
  endif()

  # Find the clang-tidy executable
  find_program(clang_tidy_exe
    NAMES "clang-tidy" "clang-tidy-15" "clang-tidy-16" "clang-tidy-17"
    HINTS "$ENV{PROGRAMFILES}/LLVM/bin"
  )

  # If clang-tidy is not found, print a warning and return
  if(NOT clang_tidy_exe)
    message(WARNING "Clang-Tidy not found")
    return()
  endif()

  # Loop over the list of targets
  foreach(target_name IN LISTS CT_TARGETS)
    message(STATUS "Enabling Clang-Tidy for target \"${target_name}\"")

    # Set the C_CLANG_TIDY and CXX_CLANG_TIDY properties for the target
    # to enable Clang-Tidy for that target
    set_target_properties("${target_name}" PROPERTIES
      C_CLANG_TIDY "${clang_tidy_exe}${CT_OPTIONS}${c_extra_args}"
      CXX_CLANG_TIDY "${clang_tidy_exe}${CT_OPTIONS}${cxx_extra_args}"
    )
  endforeach()
endfunction()
