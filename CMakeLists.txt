# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Lab5)

# Source
add_executable(Lab5 src/main.cpp src/Document.cpp src/SecureDocument.cpp)

# Headers
target_include_directories(Lab5 PRIVATE include)