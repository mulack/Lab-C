cmake_minimum_required(VERSION 3.24.2)
project(TR67)

add_library(
    tr67
    "../lib/TR67.h"
    "../src/TR67.c"
)

add_executable(main "../src/main.c")

target_link_libraries(main PRIVATE tr67)