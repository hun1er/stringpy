#-------------------------------------------------------------------------------
# Compile Options
#-------------------------------------------------------------------------------

add_compile_options(
  # Common diagnostic flags
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

  # Generate instructions for a specified machine type
  -march=x86-64-v3
)
