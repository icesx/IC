cmake_minimum_required(VERSION 3.0.0)
SET(SRC lambda.cpp)
set(so lambda)
ADD_LIBRARY(${so} SHARED ${SRC})
list(APPEND sos ${so})

