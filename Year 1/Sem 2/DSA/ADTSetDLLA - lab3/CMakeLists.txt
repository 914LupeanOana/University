cmake_minimum_required(VERSION 3.21)
project(ADTSetDLLA)

set(CMAKE_CXX_STANDARD 14)

add_executable(ADTSetDLLA main.cpp ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h SetIterator.cpp SetIterator.h Set.cpp Set.h)
