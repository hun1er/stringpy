#-------------------------------------------------------------------------------
# Compile Options
#-------------------------------------------------------------------------------

add_compile_options(
  # Warn about duplicated branches
  -Wduplicated-branches

  # Warn about duplicated conditions
  -Wduplicated-cond

  # Warn about suspicious uses of logical operators
  -Wlogical-op

  # Warn about useless casts for C++ code
  $<$<COMPILE_LANGUAGE:CXX>:-Wuseless-cast>

  # Optimize for debugging for Debug builds
  $<$<CONFIG:Debug>:-Og>

  # Optimize for size for RelWithDebInfo builds
  $<$<CONFIG:RelWithDebInfo>:-O1>

  # Generate debugging information for gdb for Debug and RelWithDebInfo builds
  $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:-ggdb>
)

# Check if the GCC compiler version is greater than or equal to 12
if(CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 12)
  set(CMAKE_C_COMPILE_OPTIONS_IPO
    -flto=auto            # Use Link Time Optimization (LTO) automatically
    -fno-fat-lto-objects  # Do not generate fat LTO objects
  )
endif()

# Check if the G++ compiler version is greater than or equal to 12
if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12)
  set(CMAKE_CXX_COMPILE_OPTIONS_IPO
    -flto=auto            # Use Link Time Optimization (LTO) automatically
    -fno-fat-lto-objects  # Do not generate fat LTO objects
  )
endif()

#-------------------------------------------------------------------------------
# Link Options
#-------------------------------------------------------------------------------

# Check if the project is using the Gold linker
if(${PNAME_UPPER}_USE_LINKER_GOLD)
  # Adds options to the LINK_OPTIONS directory property.
  # These options are used when linking targets from the current directory and below.
  add_link_options(
    # Use the gold linker
    -fuse-ld=gold

    # Warn about executable stacks
    -Wl,--warn-execstack

    # Warn about dropped version information
    -Wl,--warn-drop-version

    # Warn about shared text relocations
    -Wl,--warn-shared-textrel

    # Warn about search path mismatches
    -Wl,--warn-search-mismatch

    # Report all unresolved symbols
    -Wl,--unresolved-symbols=report-all

    # Detect ODR violations
    -Wl,--detect-odr-violations

    # Optimize for speed
    -Wl,-O3

    # Relax branch and call instructions
    -Wl,--relax

    # Perform Identical Code Folding (ICF) safely
    -Wl,--icf=safe

    # Perform 5 ICF iterations
    -Wl,--icf-iterations=5

    # Do not perform incremental linking
    -Wl,--no-incremental

    # Do not include all archive members
    -Wl,--no-whole-archive

    # Print linker statistics
    #-Wl,--stats

    # Print garbage collected sections
    #-Wl,--print-gc-sections

    # Print ICF sections
    #-Wl,--print-icf-sections

    # Do not generate unwind information for Release or MinSizeRel builds
    $<$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>>:-Wl,--no-ld-generated-unwind-info>
  )
endif()
