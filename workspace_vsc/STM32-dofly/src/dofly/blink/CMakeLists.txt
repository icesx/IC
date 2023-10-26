cmake_minimum_required(VERSION 3.0.0)
SET(SRC blink.c)
set(so blink)

add_library(${so} ${SRC})
target_compile_definitions(${so} PUBLIC -D${MCU_FAMILY})
target_include_directories(${so} PUBLIC 
    $<BUILD_INTERFACE:${STM32_CMAKE_DIR}/src/libraries/STM32F1xx_HAL_Driver/Inc>
    $<BUILD_INTERFACE:${STM32_CMAKE_DIR}/src/libraries/CMSIS/Core/Include>
    $<BUILD_INTERFACE:${STM32_CMAKE_DIR}/src/libraries/CMSIS/Device/ST/STM32F1xx/Include>)
  

