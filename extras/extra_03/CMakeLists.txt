cmake_minimum_required(VERSION 3.27.0)
project(extra_03 C)

set(CMAKE_C_STANDARD 23)

add_executable(extra_03 main.c
        labdaCircularQueue.h
        labdaCircularQueue.c)
