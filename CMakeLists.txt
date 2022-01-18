cmake_minimum_required(VERSION 3.20)
project(SS_A_21_Ex4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(SS_A_21_Ex4
        Algo.c
        Algo.h
        Graph.c
        Graph.h
        main.c)
