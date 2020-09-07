cmake_minimum_required(VERSION 3.0.0)

set(subs "base;http;gprs;sdcard;serialcamera")
set(LIB mine)
set(SRC lib.c)
add_library(${LIB} ${SRC})
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    target_link_libraries(${LIB} ${sub})
endforeach (sub)

