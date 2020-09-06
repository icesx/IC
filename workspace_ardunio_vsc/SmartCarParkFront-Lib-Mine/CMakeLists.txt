cmake_minimum_required(VERSION 3.0.0)

set(subs "base;ethernet;gprs;sdcard;serialcamera")
foreach(sub IN LISTS subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${sub})
    target_link_libraries(${PROJECT_NAME} ${sub})
endforeach (sub)

