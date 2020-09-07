cmake_minimum_required(VERSION 3.0.0)

set(subs "arduino;ethernet;sd;servo;software_serial;spi")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)

