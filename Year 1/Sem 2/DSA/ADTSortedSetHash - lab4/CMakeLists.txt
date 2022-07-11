cmake_minimum_required(VERSION 3.21)
project(ADTSortedSetHash)

set(CMAKE_CXX_STANDARD 14)

add_executable(ADTSortedSetHash main.cpp ExtendedTest.h ExtendedTest.cpp ShortTest.h ShortTest.cpp SortedSet.cpp SortedSet.h SortedSetIterator.cpp SortedSetIterator.h)
