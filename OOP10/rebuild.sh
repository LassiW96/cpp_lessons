#!/bin/bash

# Shell script to rebuild the wavegen app
# Run this from the top source directory

# Exit immediately if a command fails
set -e

# Remove old build directory
rm -rf build

# Create new build directory
mkdir build
cd build

# Run CMake
cmake ..

# Build project
make -j$(nproc)   # uses all CPU cores for faster builds

# Run the app
./wave_qt
