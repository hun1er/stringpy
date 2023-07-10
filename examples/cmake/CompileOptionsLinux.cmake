#-------------------------------------------------------------------------------
# Compile Definitions
#-------------------------------------------------------------------------------

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  add_compile_definitions(
    _DEBUG
    _FORTIFY_SOURCE=2
    _GLIBCXX_ASSERTIONS=1
    _GLIBCXX_CONCEPT_CHECKS=1
    #_GLIBCXX_DEBUG=1
    _GLIBCXX_DEBUG_PEDANTIC=1
  )
else()
  add_compile_definitions(
    NDEBUG
  )
endif()

#-------------------------------------------------------------------------------
# Compile Options
#-------------------------------------------------------------------------------

add_compile_options(
  # Common diagnostic flags
  -Wall
  -Wcast-align
  -Wcast-qual
  -Wconversion
  -Wdouble-promotion
  -Wextra
  -Wfloat-equal
  -Wformat=2
  -Wnull-dereference
  -Wpedantic
  -Wredundant-decls
  -Wshadow
  -Wsign-conversion
  -Wswitch-default
  -Wswitch-enum
  -Wundef
  -Wunused
  -Wwrite-strings

  # C++ diagnostic flags
  $<$<COMPILE_LANGUAGE:CXX>:-Wctor-dtor-privacy>
  $<$<COMPILE_LANGUAGE:CXX>:-Weffc++>
  $<$<COMPILE_LANGUAGE:CXX>:-Wextra-semi>
  $<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>
  $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
  $<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>
  $<$<COMPILE_LANGUAGE:CXX>:-Wsign-promo>
  $<$<COMPILE_LANGUAGE:CXX>:-Wzero-as-null-pointer-constant>

  -march=x86-64-v3    # Generate instructions for a specified machine type
  -mtune=generic      # Tune to the specified cpu-type everything applicable about the generated code
  -mfpmath=sse        # Use scalar floating-point instructions present in the SSE instruction set
  -pipe               # Use pipes rather than intermediate files
  -fdata-sections     # Place each data in its own section
  -ffunction-sections # Place each function in its own section

  # Optimize level 3 for Release builds
  $<$<CONFIG:Release>:-O3>

  # Don't emit extra code to check for buffer overflows
  $<$<CONFIG:Release>:-fno-stack-protector>

  # Don't keep the frame pointer in a register for functions that don't need one
  $<$<CONFIG:Release>:-fomit-frame-pointer>

  # Optimize for size for MinSizeRel builds
  $<$<CONFIG:MinSizeRel>:-Os>

  # Disable RTTI support
  $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>

  # Disable C++ exception handling
  $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>

  # Disable thread-safe initialization of local statics
  $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
)

#-------------------------------------------------------------------------------
# Link Options
#-------------------------------------------------------------------------------

add_link_options(
  # Warn about common symbols
  -Wl,--warn-common

  # Only link libraries as needed
  -Wl,--as-needed

  # Perform garbage collection of unused input sections
  -Wl,--gc-sections

  # Do not allow undefined symbols
  -Wl,--no-undefined
)

# Check if the project is not using the Gold or LLD linker
if(NOT ${PNAME_UPPER}_USE_LINKER_GOLD AND NOT ${PNAME_UPPER}_USE_LINKER_LLD)
  add_link_options(
    # Warn about alternate entry points
    -Wl,--warn-alternate-em

    # Optimize for speed
    -Wl,-O3

    # Relax branch and call instructions
    -Wl,--relax

    # Do not allow undefined symbols in shared libraries
    -Wl,--no-allow-shlib-undefined

    # Check section addresses for overlaps
    -Wl,--check-sections
  )
endif()

# Check if the build type is RelWithDebInfo
if("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
  add_link_options(
    -Wl,--discard-all                   # Discard all local symbols
    -Wl,--compress-debug-sections=zlib  # Compress debug sections using zlib
  )
endif()

# Check if the build type is Release or MinSizeRel
if("${CMAKE_BUILD_TYPE}" STREQUAL "Release" OR "${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
  add_link_options(
    -Wl,--discard-all # Discard all local symbols
    -Wl,--strip-all   # Strip all symbols
  )
endif()

#-------------------------------------------------------------------------------
# Compiler-Specific Options
#-------------------------------------------------------------------------------

strpy_include_compiler_options("${CMAKE_C_COMPILER_ID}" "C")
strpy_include_compiler_options("${CMAKE_CXX_COMPILER_ID}" "CXX")
