cmake_minimum_required(VERSION 3.0.0)
project(epollclient VERSION 0.1.0)
set(SRC EpollClient.c)
add_executable(${PROJECT_NAME} ${SRC})
