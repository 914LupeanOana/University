cmake_minimum_required(VERSION 3.21)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/oanalupean/Qt/6.2.4/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled6 main.cpp Domain.cpp Domain.h Service.cpp Service.h GUI.cpp GUI.h)
target_link_libraries(untitled6
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

