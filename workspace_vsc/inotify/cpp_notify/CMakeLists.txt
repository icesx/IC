cmake_minimum_required(VERSION 3.0.0)
SET(SRC watch.cpp
    inotify.cpp
)
set(so cpp_notify)
ADD_LIBRARY(${so} SHARED ${SRC})


