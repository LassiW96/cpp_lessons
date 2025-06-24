cmake_minimum_required(VERSION 3.10)
project(SecondDetectorProject)

set(CMAKE_CXX_STANDARED 17)

# Add the executable target
add_executable(
    detector_app_3
    main.cpp
    SecondDetector.cpp
)
