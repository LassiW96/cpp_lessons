cmake_minimum_required(VERSION 3.10)
project(WaveQtApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(wave_qt
    main.cpp
    WaveWidget.cpp
    MainWindow.cpp
)

target_link_libraries(wave_qt Qt5::Widgets)
