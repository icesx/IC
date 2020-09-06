cmake_minimum_required(VERSION 3.0.0)

set(subs "base;http;gprs;sdcard;serialcamera")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)