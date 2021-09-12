cmake_minimum_required(VERSION 3.0.0)
SET(SRC 3.2memset.c)
set(so 3)
ADD_LIBRARY(${so} SHARED ${SRC})