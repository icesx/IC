cmake_minimum_required(VERSION 3.0.0)
project(cpp_i_c VERSION 0.1.0)

set(MAIN src/cpp_ivoke_c.cpp)

add_executable(${PROJECT_NAME} ${MAIN} ${DIR_ROOT_SRCS})

aux_source_directory(. DIR_SRCS)

target_link_libraries(cpp_shard)

target_link_libraries(${PROJECT_NAME} array callback integer method string struct)
