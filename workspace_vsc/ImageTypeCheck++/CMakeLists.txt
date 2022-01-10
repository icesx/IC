cmake_minimum_required(VERSION 3.0.0)
project(image_type_check VERSION 0.1.0)
set( CMAKE_VERBOSE_MAKEFILE on )
add_executable(${PROJECT_NAME} ImageTypeCheckMain++.cpp ${DIR_ROOT_SRCS})
