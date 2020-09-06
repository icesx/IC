cmake_minimum_required(VERSION 3.0.0)
SET(SRC my_operator.cpp)

set(so operator)
ADD_LIBRARY(${so} SHARED ${SRC})



