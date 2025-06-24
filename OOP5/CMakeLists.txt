cmake_minimum_required(VERSION 3.10)
project(Scintillator_v1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Headers
include_directories(include)

# Source files
file(GLOB SOURCES
    src/Scintillator_v1.cpp
    main.cpp
)

# Build executable
add_executable(Scint_v1 ${SOURCES})
