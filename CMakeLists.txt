cmake_minimum_required(VERSION 3.10)
project(loong_third_party VERSION 4.2.5 LANGUAGES C CXX)
option(AARCH64 "aarch64" OFF)
option(RISCV64 "riscv64" OFF)
set(march x86_64)
if(AARCH64)
    set(march aarch64)
endif(AARCH64)
if(RISCV64)
    set(march riscv64)
endif(RISCV64)
set(CMAKE_C_COMPILER ${march}-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${march}-linux-gnu-g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(ethercat_${march} SHARED ethercat/lib/common.c ethercat/lib/domain.c ethercat/lib/master.c ethercat/lib/reg_request.c ethercat/lib/sdo_request.c ethercat/lib/slave_config.c ethercat/lib/soe_request.c ethercat/lib/voe_handler.c)
set_target_properties(ethercat_${march} PROPERTIES NO_SONAME ON)
set_target_properties(ethercat_${march} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/ethercat/lib")
target_include_directories(ethercat_${march} PRIVATE ${PROJECT_SOURCE_DIR}/ethercat)
add_library(modbus_${march} SHARED modbus/src/modbus.c modbus/src/modbus-data.c modbus/src/modbus-ipc.c modbus/src/modbus-rtu.c)
set_target_properties(modbus_${march} PROPERTIES NO_SONAME ON)
set_target_properties(modbus_${march} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/modbus/lib")
target_include_directories(modbus_${march} PRIVATE ${PROJECT_SOURCE_DIR}/modbus ${PROJECT_SOURCE_DIR}/modbus/include)
add_library(netlink_${march} SHARED netlink/lib/libgenl.c netlink/lib/libnetlink.c)
set_target_properties(netlink_${march} PROPERTIES NO_SONAME ON)
set_target_properties(netlink_${march} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/netlink/lib")
target_include_directories(netlink_${march} PRIVATE ${PROJECT_SOURCE_DIR}/netlink/include ${PROJECT_SOURCE_DIR}/netlink/include/uapi)
target_compile_options(netlink_${march} PRIVATE -DCONF_COLOR=COLOR_OPT_NEVER -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DHAVE_SETNS -DHAVE_HANDLE_AT -DNEED_STRLCPY)
add_library(util_${march} SHARED
    netlink/lib/utils.c
    netlink/lib/utils_math.c
    netlink/lib/rt_names.c
    netlink/lib/ll_map.c
    netlink/lib/ll_types.c
    netlink/lib/ll_proto.c
    netlink/lib/ll_addr.c
    netlink/lib/inet_proto.c
    netlink/lib/namespace.c
    netlink/lib/json_writer.c
    netlink/lib/json_print.c
    netlink/lib/json_print_math.c
    netlink/lib/names.c
    netlink/lib/color.c
    netlink/lib/bpf_legacy.c
    netlink/lib/bpf_glue.c
    netlink/lib/exec.c
    netlink/lib/fs.c
    netlink/lib/cg_map.c
    netlink/lib/ppp_proto.c
    netlink/lib/bridge.c
    netlink/lib/selinux.c
    netlink/lib/ax25_ntop.c
    netlink/lib/rose_ntop.c
    netlink/lib/mpls_ntop.c
    netlink/lib/mpls_pton.c
    netlink/lib/netrom_ntop.c
)
set_target_properties(util_${march} PROPERTIES NO_SONAME ON)
set_target_properties(util_${march} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/netlink/lib")
target_include_directories(util_${march} PRIVATE ${PROJECT_SOURCE_DIR}/netlink/include ${PROJECT_SOURCE_DIR}/netlink/include/uapi)
target_compile_options(util_${march} PRIVATE -DCONF_COLOR=COLOR_OPT_NEVER -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DHAVE_SETNS -DHAVE_HANDLE_AT -DNEED_STRLCPY)
add_library(tinyxml2_${march} SHARED tinyxml2/src/tinyxml2.cpp)
set_target_properties(tinyxml2_${march} PROPERTIES NO_SONAME ON)
set_target_properties(tinyxml2_${march} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/tinyxml2/lib")
target_include_directories(tinyxml2_${march} PRIVATE ${PROJECT_SOURCE_DIR}/tinyxml2/include)