cmake_minimum_required(VERSION 3.0.0)
SET(SRC test_vector.cpp)
set(so vector)
ADD_LIBRARY(${so} SHARED ${SRC})




