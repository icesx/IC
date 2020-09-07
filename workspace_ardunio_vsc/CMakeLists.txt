cmake_minimum_required(VERSION 3.0.0)
set( CMAKE_VERBOSE_MAKEFILE on )
message(STATUS "src This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})
project(ardunio VERSION 0.1.0)
set(CMAKE_C_COMPILER /TOOLS/software/arduino-1.8.11/hardware/tools/avr/bin/avr-gcc)
set(CMAKE_CXX_COMPILER /TOOLS/software/arduino-1.8.11/hardware/tools/avr/bin/avr-g++)
set(CMAKE_CXX_FLAGS "-O2")
# include
message("CMAKE_CURRENT_LIST_DIR====${CMAKE_CURRENT_LIST_DIR}")
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/SmartCarParkFront-Lib
    ${CMAKE_CURRENT_LIST_DIR}/SmartCarParkFront-Lib-Mine
    ${CMAKE_CURRENT_LIST_DIR}/SmartCarParkFront-Lib/arduino
    ${CMAKE_CURRENT_LIST_DIR}/include/variants/mega
    )

# 宏
add_definitions(
    -DF_CPU=16000000L
    -D__AVR_ATmega2560__
    -DARDUINO_ARCH_AVR
)
set(subs "SmartCarParkFront-Lib-Mine;SmartCarParkFront-Lib")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)

