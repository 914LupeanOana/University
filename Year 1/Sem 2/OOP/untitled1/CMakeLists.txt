cmake_minimum_required(VERSION 3.21)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c country.h country.c Country_Repository.c Country_Repository.h Service.h Service.c ui.h ui.c dynamic_array.h dynamic_array.c test.h test.c)
