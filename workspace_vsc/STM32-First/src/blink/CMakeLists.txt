cmake_minimum_required(VERSION 3.0.0)
SET(SRC BlinkLed.cpp
)
set(so blink)
ADD_LIBRARY(${so} SHARED ${SRC})