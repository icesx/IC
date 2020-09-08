aux_source_directory(. SRC)
set(SO software_serial)
add_library(${SO} OBJECT ${SRC})
