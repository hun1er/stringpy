include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Set the value of ${PNAME_UPPER}_INSTALL_CMAKEDIR if it's not already defined
if(NOT DEFINED ${PNAME_UPPER}_INSTALL_CMAKEDIR)
  set(${PNAME_UPPER}_INSTALL_CMAKEDIR
    "${CMAKE_INSTALL_LIBDIR}/cmake/${PNAME_CAPITALIZED}"
    CACHE STRING "Path to ${PNAME_CAPITALIZED} CMake files"
  )
endif()

# Generates an install target for the project.
function(generate_install_target)
  set(rt_component "${PNAME_LOWER}")
  set(dev_component "${rt_component}-dev")
  set(targets_export "${PNAME_CAPITALIZED}Targets")
  set(config_file "${PNAME_CAPITALIZED}Config.cmake")
  set(config_version_file "${PNAME_CAPITALIZED}ConfigVersion.cmake")

  # Configure the package config file
  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in" "${config_file}"

    INSTALL_DESTINATION
      "${${PNAME_UPPER}_INSTALL_CMAKEDIR}"
  )

  # Write the basic package version file
  write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/${config_version_file}"
    COMPATIBILITY "SameMajorVersion"
  )

  # Install the target and its components
  install(
    TARGETS
      "${PNAME_LOWER}"

    EXPORT
      "${targets_export}"

    RUNTIME
      COMPONENT "${rt_component}"

    LIBRARY
      COMPONENT "${rt_component}"
      NAMELINK_COMPONENT "${dev_component}"

    ARCHIVE
      COMPONENT "${dev_component}"

    INCLUDES
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"

    PUBLIC_HEADER
      COMPONENT "${dev_component}"
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PNAME_LOWER}"
  )

  # Install the targets export
  install(
    EXPORT
      "${targets_export}"

    COMPONENT
      "${dev_component}"

    DESTINATION
      "${${PNAME_UPPER}_INSTALL_CMAKEDIR}"

    NAMESPACE
      "${PNAME_CAPITALIZED}::"
  )

  # Install the Config and ConfigVersion files
  install(
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/${config_file}"
      "${CMAKE_CURRENT_BINARY_DIR}/${config_version_file}"

    COMPONENT
      "${dev_component}"

    DESTINATION
      "${${PNAME_UPPER}_INSTALL_CMAKEDIR}"
  )

  # If building on MSVC, install the pdb file if necessary
  if(MSVC)
    if(BUILD_SHARED_LIBS)
      set(pdb_file "$<TARGET_PDB_FILE:${PNAME_LOWER}>")
      set(pdb_file_destination "${CMAKE_INSTALL_BINDIR}")
    else() # TARGET_PDB_FILE does not work for pdb file generated for static library build, determining it manually
      set(pdb_file "$<TARGET_FILE_DIR:${PNAME_LOWER}>/$<TARGET_FILE_PREFIX:${PNAME_LOWER}>$<TARGET_FILE_BASE_NAME:${PNAME_LOWER}>.pdb")
      set(pdb_file_destination "${CMAKE_INSTALL_LIBDIR}")
    endif()

    install(
      FILES
        "${pdb_file}"

      COMPONENT
        "${dev_component}"

      CONFIGURATIONS
        "Debug" "RelWithDebInfo"

      DESTINATION
        "${pdb_file_destination}"

      OPTIONAL
    )
  endif()
endfunction()
