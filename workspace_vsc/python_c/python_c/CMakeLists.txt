cmake_minimum_required(VERSION 3.0.0)

SET(SRC python_c.c
    
)
set(so python_c)
ADD_LIBRARY(${so} SHARED ${SRC})




