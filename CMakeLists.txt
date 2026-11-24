# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Lab6)

# Source
add_executable(Lab6 src/main.cpp src/Resource.cpp src/MutexLock.cpp)

# Headers
target_include_directories(Lab6 PRIVATE include)