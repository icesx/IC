cmake_minimum_required(VERSION 3.0.0)

set(subs "arduino;ethernet;sd;sd_fs;servo;software_serial;spi;w5100")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)

