cmake_minimum_required(VERSION 3.21)
project(e914-914LupeanOana-1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/oanalupean/Qt/6.2.4/macos/lib/cmake")

file(COPY drivers.txt
        DESTINATION ${CMAKE_BINARY_DIR})
file(COPY roads.txt
        DESTINATION ${CMAKE_BINARY_DIR})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(e914_914LupeanOana_1 domain/driver.cpp domain/driver.h domain/observer.h domain/road.cpp domain/road.h repository/CodeRepository.cpp repository/CodeRepository.h ui/DriverWindow.cpp ui/DriverWindow.h main.cpp)
target_link_libraries(e914_914LupeanOana_1
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
