cmake_minimum_required(VERSION 3.5)

project(sharedapi)
add_compile_options(-fPIC)

include_directories("./" "../add" "../sub")
link_directories(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

add_library(sharedapi SHARED sharedlib.h sharedlib.cpp)
target_link_libraries(sharedapi jadd jsub)
