# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Lab4)

# Source
add_executable(Lab4 src/main.cpp src/House.cpp)

# Headers
target_include_directories(Lab4 PRIVATE include)