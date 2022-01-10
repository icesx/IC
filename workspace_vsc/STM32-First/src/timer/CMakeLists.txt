cmake_minimum_required(VERSION 3.0.0)
SET(SRC Timer.cpp
)
set(so timer)
ADD_LIBRARY(${so} SHARED ${SRC})