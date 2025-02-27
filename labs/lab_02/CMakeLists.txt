cmake_minimum_required(VERSION 3.29)
project(lab_02 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_02 main.c
        utils.h)

target_link_libraries(lab_02 ${PROJECT_SOURCE_DIR}/lib/libuntitled.a)