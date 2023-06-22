# Runs Clang-Format on the source files of a target before building it.
#
# @param TARGETS The list of target names to run Clang-Format on.
# @param STYLE [optional] The coding style option to pass to Clang-Format.
# @param WORKING_DIRECTORY [optional] The working directory for the Clang-Format.
function(format_target_sources)
  # Parse the arguments passed to the function
  cmake_parse_arguments("FTS" "" "STYLE;WORKING_DIRECTORY" "TARGETS" ${ARGN})

  # If TARGETS is not set, print an error message and stop processing
  if(NOT FTS_TARGETS)
    message(FATAL_ERROR "TARGETS is not set.")
  endif()

  # If STYLE is not set, use "file" as the default value
  if(NOT FTS_STYLE)
    set(FTS_STYLE "file")
  endif()

  # If WORKING_DIRECTORY is not set, use the CMAKE_CURRENT_SOURCE_DIR as the default value
  if(NOT FTS_WORKING_DIRECTORY)
    set(FTS_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
  endif()

  # Find the Clang-Format executable
  find_program(clang_format_exe
    NAMES "clang-format" "clang-format-15" "clang-format-16" "clang-format-17"
    HINTS "$ENV{PROGRAMFILES}/LLVM/bin"
  )

  # If Clang-Format is not found, print a status message and return
  if(NOT clang_format_exe)
    message(STATUS "Clang-Format not found")
    return()
  endif()

  # Loop over the list of targets
  foreach(target_name IN LISTS FTS_TARGETS)
    message(STATUS "Enabling Clang-Format for target \"${target_name}\"")

    # Get the list of source files associated with the target
    unset(target_sources)
    get_target_property(target_sources "${target_name}" SOURCES)

    # Add a custom command to run Clang-Format on the target's source files before building the target
    add_custom_command(TARGET "${target_name}" PRE_BUILD
      WORKING_DIRECTORY "${FTS_WORKING_DIRECTORY}"
      COMMAND ${clang_format_exe} -i --style=${FTS_STYLE} ${target_sources}
    )
  endforeach()
endfunction()
