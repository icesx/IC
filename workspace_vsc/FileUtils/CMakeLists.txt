cmake_minimum_required(VERSION 3.0.0)
project(FILEUTILS VERSION 0.1.0)

include(CTest)
enable_testing()

set(SRC FileUtils.c)
add_executable(${PROJECT_NAME} ${SRC})
set(subs "fu")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${sub})
    target_link_libraries(${PROJECT_NAME} ${sub})
endforeach (sub)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
