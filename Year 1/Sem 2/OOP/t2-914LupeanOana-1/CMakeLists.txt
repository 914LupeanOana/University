cmake_minimum_required(VERSION 3.21)
project(t2_914LupeanOana_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2_914LupeanOana_1
        Car.cpp
        Car.h
        ElectricEngine.cpp
        ElectricEngine.h
        Engine.cpp
        Engine.h
        main.cpp
        Service.cpp
        Service.h
        TurboEngine.cpp
        TurboEngine.h
        UI.cpp
        UI.h)
