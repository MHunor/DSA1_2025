cmake_minimum_required(VERSION 3.27.0)
project(extra_02 C)

set(CMAKE_C_STANDARD 23)

add_executable(extra_02 main.c
        labdaSimpleQueue.c
        labdaSimpleQueue.h)
