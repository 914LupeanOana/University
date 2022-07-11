cmake_minimum_required(VERSION 3.21)
project(a5_6_914LupeanOana)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a5_6_914LupeanOana
        AdministratorService.cpp
        AdministratorService.h
        Main.cpp
        Movie.cpp
        Movie.h
        Repository.cpp
        Repository.h
        Ui.cpp
        Ui.h
        UserService.cpp
        UserService.h
        Validator.cpp
        Validator.h
        DynamicVector.h
        tests.h
        tests.cpp
        )
