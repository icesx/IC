cmake_minimum_required(VERSION 3.0.0)
SET(SRC mysql.c)
set(so sql)
ADD_LIBRARY(${so} SHARED ${SRC})