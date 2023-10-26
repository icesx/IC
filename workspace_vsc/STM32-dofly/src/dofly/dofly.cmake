set(DOFLY_DIR ${CMAKE_CURRENT_LIST_DIR})
add_subdirectory(dofly)
include_directories(${DOFLY_DIR}/blink)
target_link_libraries(${ELF_TARGET} PUBLIC blink -lc -lm -lnosys)