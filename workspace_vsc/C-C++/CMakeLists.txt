cmake_minimum_required(VERSION 3.0.0)
set( CMAKE_VERBOSE_MAKEFILE on )
message(STATUS "src This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})
project(ccp VERSION 0.1.0)
#0 is c ivoke c++
# set(IVOKE 0)
set(IVOKE 0)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
if (${IVOKE} EQUAL 1)
    message("c++ ivoke c")
    set(SHARD_PATH lib_c_shard)
    set(LIB c_shard)
    set(EXE_PATH cpp_i_c)
else()
    message("c ivoke c++")
    set(SHARD_PATH lib_cpp_shard)
    set(LIB cpp_shard)
    set(EXE_PATH c_i_cpp)
endif()
link_directories(
    ${PROJECT_BINARY_DIR}/lib_cpp_shard
    ${PROJECT_BINARY_DIR}/lib_c_shard
)
message("SHARD_PATH=${SHARD_PATH}")
add_subdirectory(${SHARD_PATH})
add_subdirectory(${EXE_PATH})

