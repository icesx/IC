aux_source_directory(. SRC)
set(SRC
    ${SRC}
    wiring_pulse.s.S
)
set(SO arduino)
add_library(${SO} OBJECT ${SRC})
