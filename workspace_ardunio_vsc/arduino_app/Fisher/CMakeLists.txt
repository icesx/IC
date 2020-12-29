#=============================================================================#
# Author: QueezyTheGreat                                                      #
# Date:   26.04.2011                                                          #
#                                                                             #
# Description: Arduino CMake example                                          #
#                                                                             #
#=============================================================================#



cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain
#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(ArduinoExample)

print_board_list()
print_programmer_list()

add_subdirectory(example)   #add the example directory into build
