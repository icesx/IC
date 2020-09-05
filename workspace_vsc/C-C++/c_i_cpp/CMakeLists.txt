cmake_minimum_required(VERSION 3.0.0)
set( CMAKE_VERBOSE_MAKEFILE on )
project(c_i_cpp VERSION 0.1.0)

aux_source_directory(src DIR_LIB_SRCS)

set_source_files_properties(src/c_ivoke_cpp.c PROPERTIES LANGUAGE CXX )

set(MAIN src/c_ivoke_cpp.c
src/proxy_module.cpp)

message("LIB==========${LIB}")

add_executable(${PROJECT_NAME} ${MAIN})

target_link_libraries(${LIB})



