cmake_minimum_required(VERSION 3.0.0)
set( CMAKE_VERBOSE_MAKEFILE on )
message(STATUS "src This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})
project(ardunio VERSION 0.1.0)

set(subs "SmartCarParkFront-Lib-Mine;SmartCarParkFront-Lib")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)


message("SHARD_PATH=${SHARD_PATH}")
add_subdirectory(${SHARD_PATH})
add_subdirectory(${EXE_PATH})

