#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Necro::qiuniu" for configuration ""
set_property(TARGET Necro::qiuniu APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Necro::qiuniu PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/${_necro_libdir}/libqiuniu.so"
  IMPORTED_SONAME_NOCONFIG "libqiuniu.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS Necro::qiuniu )
list(APPEND _IMPORT_CHECK_FILES_FOR_Necro::qiuniu "${_IMPORT_PREFIX}/${_necro_libdir}/libqiuniu.so" )

# Import target "Necro::modechk" for configuration ""
set_property(TARGET Necro::modechk APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Necro::modechk PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/${_necro_libdir}/libmodechk.so"
  IMPORTED_SONAME_NOCONFIG "libmodechk.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS Necro::modechk )
list(APPEND _IMPORT_CHECK_FILES_FOR_Necro::modechk "${_IMPORT_PREFIX}/${_necro_libdir}/libmodechk.so" )

# Import target "Necro::copperplate" for configuration ""
set_property(TARGET Necro::copperplate APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Necro::copperplate PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/${_necro_libdir}/libcopperplate.so"
  IMPORTED_SONAME_NOCONFIG "libcopperplate.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS Necro::copperplate )
list(APPEND _IMPORT_CHECK_FILES_FOR_Necro::copperplate "${_IMPORT_PREFIX}/${_necro_libdir}/libcopperplate.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
