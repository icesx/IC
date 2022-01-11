cmake_minimum_required(VERSION 3.0.0)
set( CMAKE_VERBOSE_MAKEFILE on )
project(xx VERSION 0.1.0)
message(STATUS "src This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})
set(AVR_PATH /TOOLS/IDE/arduino/hardware/tools/avr/bin)
set(CMAKE_C_COMPILER ${AVR_PATH}/avr-gcc)
set(CMAKE_CXX_COMPILER ${AVR_PATH}/avr-g++)
set(CMAKE_OBJCOPY ${AVR_PATH}/avr-objcopy)

set(ARDUINO_PATH "/TOOLS/IDE/arduino")


set(CMAKE_CXX_FLAGS "-O2 -Wwrite-strings")
# include
message("CMAKE_CURRENT_LIST_DIR====${CMAKE_CURRENT_LIST_DIR}")
INCLUDE_DIRECTORIES(
    ${ARDUINO_PATH}/hardware/arduino/avr/variants/mega
    ${ARDUINO_PATH}/hardware/arduino/avr/cores/arduino
    )

# 宏
add_definitions(
    -DF_CPU=16000000L
    -D__AVR_ATmega2560__
    -DARDUINO_ARCH_AVR
    -mmcu=atmega2560 
    -g2
    -gstabs
    -Os 
    -fpack-struct 
    -fshort-enums 
    -ffunction-sections 
    -fdata-sections 
    -funsigned-char 
    -funsigned-bitfields 
    -fno-exceptions
    -MMD 
    -MP
)
set(subs "blink")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${sub})
endforeach (sub)

add_executable("finsher" fisher.cpp)



SET(TARGET_NAME,"finsher")
set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ".elf")
set_target_properties(${TARGET_NAME} PROPERTIES
                        COMPILE_FLAGS "${ARDUINO_COMPILE_FLAGS} ${COMPILE_FLAGS}"
                        LINK_FLAGS "${ARDUINO_LINK_FLAGS} ${LINK_FLAGS}"
)

set(TARGET_PATH ${EXECUTABLE_OUTPUT_PATH}/${TARGET_NAME})

set(ARDUINO_OBJCOPY_HEX_FLAGS
    
    )
  
# Convert firmware image to ASCII HEX format
add_custom_command(OUTPUT ${TARGET_NAME}.hex
                        POST_BUILD
                        COMMAND ${CMAKE_OBJCOPY}
                        ARGS    ${ARDUINO_OBJCOPY_HEX_FLAGS}
                                ${TARGET_PATH}.elf
                                ${TARGET_PATH}.hex
                        COMMENT "Generating HEX image"
                        VERBATIM)



