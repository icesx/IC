cmake_minimum_required(VERSION 3.0.0)
set( CMAKE_VERBOSE_MAKEFILE on )
project(cpp_i_c VERSION 0.1.0)

aux_source_directory(src DIR_LIB_SRCS)

set(MAIN src/cpp_ivoke_c.cpp)

message("LIB==========${LIB}")

add_executable(${PROJECT_NAME} ${MAIN})
target_link_libraries(${PROJECT_NAME} ${LIB})



