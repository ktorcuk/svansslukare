cmake_minimum_required(VERSION 3.27)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
add_executable(untitled2 main.cpp
        event.cpp
        GameFunction.cpp
        inc/functions.h
        functions.cpp
)
