cmake_minimum_required(VERSION 3.0.0)
project(cpp_shard VERSION 0.1.0)
aux_source_directory(. DIR_LIB_SRCS)
SET(SRC src/c_module.c)
ADD_LIBRARY(${LIB} SHARED ${SRC})

