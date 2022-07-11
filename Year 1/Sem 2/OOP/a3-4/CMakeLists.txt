cmake_minimum_required(VERSION 3.21)
project(a3_4 C)

set(CMAKE_C_STANDARD 11)

add_library(a3_4 library.c domain.h domain.c dynamic_array.h dynamic_array.c repository.h reposiotry.c main.c)
