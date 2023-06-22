#-------------------------------------------------------------------------------
# Compile Options
#-------------------------------------------------------------------------------

add_compile_options(
  # Optimize for debugging for Debug builds
  $<$<CONFIG:Debug>:-Og>

  # Optimize for size for RelWithDebInfo builds
  $<$<CONFIG:RelWithDebInfo>:-O1>

  # Generate debugging information for gdb for Debug and RelWithDebInfo builds
  $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:-ggdb>
)

#-------------------------------------------------------------------------------
# Link Options
#-------------------------------------------------------------------------------

# Check if the project is using the LLD linker
if(${PNAME_UPPER}_USE_LINKER_LLD)
  # Adds options to the LINK_OPTIONS directory property.
  # These options are used when linking targets from the current directory and below.
  add_link_options(
    # Use LLD linker
    -fuse-ld=lld

    # Warn about backreferences in linker scripts
    -Wl,--warn-backrefs

    # Warn about text relocations in ifunc symbols
    -Wl,--warn-ifunc-textrel

    # Warn about out-of-order symbols
    -Wl,--warn-symbol-ordering

    # Optimize for speed
    -Wl,-O2

    # Use LTO optimization level 3 for Release and MinSizeRel builds
    $<$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>>:-Wl,--lto-O3>

    # Perform Identical Code Folding (ICF) safely
    -Wl,--icf=safe

    # Do not use legacy pass manager for LTO
    -Wl,--no-lto-legacy-pass-manager

    # Check section addresses for overlaps
    -Wl,--check-sections

    # Print removed unused sections
    #-Wl,--print-gc-sections

    # Print folded identical sections
    #-Wl,--print-icf-sections
  )
endif()
