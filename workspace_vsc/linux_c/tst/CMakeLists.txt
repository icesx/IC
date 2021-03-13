cmake_minimum_required(VERSION 3.0.0)
project(linux_c VERSION 0.1.0)
set(SRC main.c)

set(BINARY ${CMAKE_PROJECT_NAME}_tst)

set(subs "clang")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${sub})
    target_link_libraries(${PROJECT_NAME} ${sub})
endforeach (sub)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)