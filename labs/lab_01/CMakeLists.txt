cmake_minimum_required(VERSION 3.29)
project(lab_01 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_01 main.c
        arr.c
        arr.h)

target_link_libraries(lab_01 ${PROJECT_SOURCE_DIR}/lib/libuntitled.a)