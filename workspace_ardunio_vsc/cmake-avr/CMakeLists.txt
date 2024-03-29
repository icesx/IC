CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

PROJECT(cmake-avr)
SET(MCU_SPEED "16000000")
SET(AVR_MCU "atmega2560")
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc4)
set(AVR_PROGRAMMER stk500v2)
set(AVR_UPLOADTOOL_PORT /dev/ttyUSB0)
set(CMAKE_BUILD_TYPE Release)
set(ARDUINO_PATH "/TOOLS/IDE/arduino")
set(ARDUINO_LIB_HOME /ICESX/workSpaceC/IC/workspace_ardunio_vsc/arduino_lib)
INCLUDE_DIRECTORIES(
    ${ARDUINO_PATH}/hardware/arduino/avr/variants/mega
    ${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino
    ${ARDUINO_PATH}/hardware/tools/avr/avr/include
    ${ARDUINO_LIB_HOME}/libavr-mine
    ${ARDUINO_LIB_HOME}/libavr-base
    )

SET(CMAKE_AVR_SOURCE_EXE
        main.c
)
SET(CMAKE_AVR_SUB_LIB 
        blink
)
SET(CMAKE_AVR_LINK_LIB_PATH
        ${ARDUINO_LIB_HOME}/build/libavr-base
        ${ARDUINO_LIB_HOME}/build/libavr-mine
)
SET(CMAKE_AVR_LINK_LIBS_NAME
        avr-mine
        avr-base
)
add_compile_options(
    -mmcu=${AVR_MCU}
    -O2
    -Wall
    -g2
    -gstabs
    -fpack-struct
    -fshort-enums
    -ffunction-sections
    -fdata-sections
    -funsigned-char
    -funsigned-bitfields
    -fno-exceptions
    -mmcu=atmega2560
    
)
add_definitions(
    -DF_CPU=${MCU_SPEED}
    -D__AVR_ATmega2560__
    -DARDUINO_AVR_MEGA2560
    -DARDUINO_ARCH_AVR
)



include(../avr-gcc.cmake)