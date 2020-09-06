cmake_minimum_required(VERSION 3.0.0)

SET(SRC child.cpp
    driver.cpp
)
set(so clazz)
ADD_LIBRARY(${so} SHARED ${SRC})




