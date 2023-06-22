#-------------------------------------------------------------------------------
# Compile Options
#-------------------------------------------------------------------------------

add_compile_options(
  /cgthreads${PROCESSOR_CORES}  # Number of cl.exe threads to use for optimization and code generation
  /external:anglebrackets       # Treat all headers included via <> as external
  /external:templates-          # Evaluate warning level across template instantiation chain
  /external:W0                  # Warning level for external headers
  /MP${PROCESSOR_CORES}         # Build with multiple processes
  /options:strict               # Unrecognized compiler options are errors
  /validate-charset             # Validate UTF-8 files for only compatible characters
)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  add_compile_options(
    /GS                         # Checks buffer security
    /RTC1                       # Runtime checks
    /sdl                        # Enable more security features and warnings
  )
else()
  add_compile_options(
    /Qpar                       # Automatic parallelization of loops
  )
endif()

#-------------------------------------------------------------------------------
# Link Options
#-------------------------------------------------------------------------------

add_link_options(
  /CGTHREADS:${PROCESSOR_CORES} # Number of cl.exe threads to use for optimization and code generation
)
