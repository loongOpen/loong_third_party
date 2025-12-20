
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was necro-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

include(CMakeFindDependencyMacro)
find_dependency(Threads)

set(_necro_threadlib "Threads::Threads")
if(CMAKE_VERSION VERSION_LESS 3.1)
  set(_necro_threadlib "${CMAKE_THREAD_LIBS_INIT}")
endif()

set(_necro_includedir "include")
set(_necro_libdir "lib")

include(${CMAKE_CURRENT_LIST_DIR}/necro-targets.cmake)
check_required_components(Necro)

include(${CMAKE_CURRENT_LIST_DIR}/necro-macros.cmake)

unset(_necro_threadlib)
unset(_necro_libdir)
unset(_necro_includedir)
