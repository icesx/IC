cmake_minimum_required(VERSION 3.0.0)
SET(SRC 2.1ssys.c)
set(so 2)
ADD_LIBRARY(${so} SHARED ${SRC})