CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

PROJECT(cmake-avr)
SET(MCU_SPEED "16000000")
SET(AVR_MCU "atmega2560")
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc4)
set(AVR_PROGRAMMER stk500v2)
set(AVR_UPLOADTOOL_PORT /dev/ttyUSB0)
set(CMAKE_BUILD_TYPE Release)
set(ARDUINO_PATH "/TOOLS/IDE/arduino")
INCLUDE_DIRECTORIES(
    ${ARDUINO_PATH}/hardware/arduino/avr/variants/mega
    ${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino
    ${ARDUINO_PATH}/hardware/tools/avr/avr/include
    )

SET(CMAKE_AVR_SOURCE_EXE
        main.c
)
SET(CMAKE_AVR_SUB_LIB 
        blink
)
SET(CMAKE_AVR_LINK_LIB_PATH
        /ICESX/workSpaceC/IC/workspace_eclipse/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/ATMEGA_LIB
)
SET(CMAKE_AVR_LINK_LIBS_NAME
        SmartCarParkFront-Lib
)


##########################################################################
# compiler options for all build types
##########################################################################
add_definitions("-DF_CPU=${MCU_SPEED}")
#add_definitions("-fpack-struct")
#add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
#add_definitions("-pedantic")
#add_definitions("-pedantic-errors")
#add_definitions("-funsigned-char")
#add_definitions("-funsigned-bitfields")
#add_definitions("-ffunction-sections")
#add_definitions("-c")
add_definitions("-std=gnu99")
add_definitions("-mmcu=${AVR_MCU}")

##########################################################################

include(avr-gcc.cmake)