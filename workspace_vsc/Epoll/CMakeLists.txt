cmake_minimum_required(VERSION 3.0.0)
project(method_point VERSION 0.1.0)
set(SRC epoll-server.c)
add_executable(${PROJECT_NAME} ${SRC})
