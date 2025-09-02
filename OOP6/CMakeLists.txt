cmake_minimum_required(VERSION 3.10)
project(Detector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Headers
include_directories(include)

# Source files
file(GLOB SOURCES
    src/Detector.cpp
    main.cpp
)

# Build executable
add_executable(Generic_detector ${SOURCES})
