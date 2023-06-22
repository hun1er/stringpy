#-------------------------------------------------------------------------------
# Compile Options
#-------------------------------------------------------------------------------

add_compile_options(
  /W4                           # Output warning level
  /permissive-                  # Standard-conformance mode
  /utf-8                        # Specifies both the source character set and the execution character set as UTF-8
  /Zc:threadSafeInit-           # Thread-safe local static initialization

  # Disable RTTI support
  $<$<COMPILE_LANGUAGE:CXX>:/GR->

  # Checks buffer security
  $<$<CONFIG:Debug>:/GS>
)

#-------------------------------------------------------------------------------
# Compiler-Specific Options
#-------------------------------------------------------------------------------

include_compiler_options("${CMAKE_C_COMPILER_ID}" "C")
include_compiler_options("${CMAKE_CXX_COMPILER_ID}" "CXX")
