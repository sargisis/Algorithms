# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(GraphProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

# Add source files (where graph.cpp is located)
add_executable(GraphApp main.cpp graph.h graph.hpp)

