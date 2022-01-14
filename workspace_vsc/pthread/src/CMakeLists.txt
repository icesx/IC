cmake_minimum_required(VERSION 3.0.0)

SET(SRC complex.c
    sample.c
)
set(so src)
ADD_LIBRARY(${so} SHARED ${SRC})




