cmake_minimum_required(VERSION 3.0.0)
project(ILC VERSION 0.1.0)

add_executable(${PROJECT_NAME} src/ILearn.c ${DIR_ROOT_SRCS})

aux_source_directory(. DIR_SRCS)

add_subdirectory(src/array)
target_link_libraries(array)

add_subdirectory(src/callback)

add_subdirectory(src/integer)
target_link_libraries(integer)
add_subdirectory(src/method)
target_link_libraries(method)
add_subdirectory(src/string)
target_link_libraries(string)
add_subdirectory(src/struct)
target_link_libraries(struct)

target_link_libraries(${PROJECT_NAME} array callback integer method string struct)
