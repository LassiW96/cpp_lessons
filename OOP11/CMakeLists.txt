cmake_minimum_required(VERSION 3.10)
project(Experiment)

set(CMAKE_CXX_STANDARD 17)

##set(CMAKE_AUTOMOC ON)
##set(CMAKE_AUTOUIC ON)
##set(CMAKE_AUTORCC ON)

add_executable(Experiment
    main.cpp
)

target_link_libraries(Experiment)
