cmake_minimum_required(VERSION 3.27.0)
project(lab_08 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_08 main.c
        labdaStack.h
        labdaStack.c)
