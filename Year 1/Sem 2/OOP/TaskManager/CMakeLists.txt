cmake_minimum_required(VERSION 3.21)
project(TaskManager)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/oanalupean/Qt/6.2.4/macos/lib/cmake")

file(COPY programmer.txt
        DESTINATION ${CMAKE_BINARY_DIR})
file(COPY task.txt
        DESTINATION ${CMAKE_BINARY_DIR})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TaskManager main.cpp domain/observer.h domain/Programmer.cpp domain/Programmer.h domain/Task.cpp domain/Task.h repository/CodeRepository.cpp repository/CodeRepository.h ui/ProgrammerWindow.cpp ui/ProgrammerWindow.h)
target_link_libraries(TaskManager
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

