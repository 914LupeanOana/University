cmake_minimum_required(VERSION 3.21)
project(a11_12)

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

include_directories(.)
include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(UI)

add_executable(a11_12 main.cpp
        Domain/Movie.cpp
        Domain/Movie.h
        Repository/DynamicVector.h
        Repository/Repository.cpp
        Repository/Repository.h
        Repository/WatchList.cpp
        Repository/WatchList.h
        Service/Service.cpp
        Service/Service.h
        Tests/Tests.cpp
        Tests/Tests.h
        UI/UI.cpp
        UI/UI.h
        main.cpp
        Exceptions/Exceptions.cpp
        Exceptions/Exceptions.h
        Exceptions/Validators.cpp
        Exceptions/Validators.h
        Repository/CSV_Watchlist.cpp
        Repository/CSV_Watchlist.h
        Repository/HTML_Watchlist.cpp
        Repository/HTML_Watchlist.h
        GUI/gui.cpp
        GUI/gui.h
        GUI/gui.ui GUI/csv_html_gui/csv_html_gui.cpp GUI/csv_html_gui/csv_html_gui.h GUI/csv_html_gui/csv_html_gui.ui Domain/Operation.cpp Domain/Operation.h)
find_library(a11_12 Watchlist.csv Files)
target_link_libraries(a11_12
        Qt::Core
        Qt::Gui
        Qt::Widgets

        )

