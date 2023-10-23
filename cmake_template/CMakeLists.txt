cmake_minimum_required(VERSION 3.0.0)
project(cmake-template VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE on )
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
INCLUDE_DIRECTORIES(
    /TOOLS/SDK/opencv/include/opencv4
    ./src
    )

set(subs "src")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)
