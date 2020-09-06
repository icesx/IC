cmake_minimum_required(VERSION 3.0.0)
SET(SRC notify.c)
set(so c_notify)
ADD_LIBRARY(${so} SHARED ${SRC})


