cmake_minimum_required(VERSION 3.0.0)
aux_source_directory(. DIR_LIB_SRCS)
add_library(method ${DIR_LIB_SRCS})
