cmake_minimum_required(VERSION 3.1)
project(untitled3 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled3 main.c
        adc.c
        adc.h
        io.c
        io.h
        stats.c
        stats.h)
