cmake_minimum_required(VERSION 3.0.0)
SET(SRC 17.1.c)
set(so 17.1)
ADD_LIBRARY(${so} SHARED ${SRC})