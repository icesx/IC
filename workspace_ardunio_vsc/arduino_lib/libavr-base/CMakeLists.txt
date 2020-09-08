cmake_minimum_required(VERSION 3.0.0)

set(subs "arduino;ethernet;sd;servo;software_serial;spi")
#=================#
set(NAME lib-avr-base)
set(LIB avr-base)
set(MAIN_SRC lib.c)
add_library(${LIB} ${MAIN_SRC})
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${NAME}/${sub})
endforeach (sub)
target_link_libraries(${LIB} ${subs})

