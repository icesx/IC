cmake_minimum_required(VERSION 3.0.0)
project(point VERSION 0.1.0)


INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_LIST_DIR}/python_c
    )

set(subs "python_c")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${sub})
endforeach (sub)
