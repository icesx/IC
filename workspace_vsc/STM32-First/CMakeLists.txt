cmake_minimum_required(VERSION 3.0.0)
project(auth-face VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE on )
set(CMAKE_C_COMPILER /TOOLS/GCC/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /TOOLS/GCC/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-g++)
set(CMAKE_CXX_FLAGS "-O2 -Wwrite-strings -std=gnu++11")

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_LIST_DIR}/include
    )

set(subs "blink;timer")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("src/${sub}")
    link_directories(${PROJECT_BINARY_DIR}/src/${sub})
    target_link_libraries(${sub})
endforeach (sub)
set(MAIN_SRC main.cpp)
ADD_LIBRARY(${PROJECT_NAME} SHARED ${MAIN_SRC})