cmake_minimum_required(VERSION 3.21)
project(t1_914LupeanOana_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_914LupeanOana_1
        DynamicVector.h
        exception.cpp
        exception.h
        main.cpp
        repository.cpp
        repository.h
        school.cpp
        school.h
        service.cpp
        service.h
        ui.cpp
        ui.h)
