cmake_minimum_required(VERSION 3.0.0)
SET(SRC BinaryInt.cpp)
set(so my_integer)
ADD_LIBRARY(${so} SHARED ${SRC})


