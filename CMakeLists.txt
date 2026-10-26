# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Lab3)

# Source
add_executable(Lab3 src/main.cpp src/Truck.cpp src/BadTruck.cpp)

# Headers
target_include_directories(Lab3 PRIVATE include)