cmake_minimum_required(VERSION 3.0.0)
project(point VERSION 0.1.0)
set(SRC main.c)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_LIST_DIR}/src
    )

add_executable(${PROJECT_NAME} ${SRC})
set(subs "src")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${sub})
    target_link_libraries(${PROJECT_NAME} ${sub})
endforeach (sub)
