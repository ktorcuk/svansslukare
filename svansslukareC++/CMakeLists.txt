cmake_minimum_required(VERSION 3.27)
project(svansslukareC__)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

add_executable(svansslukareC__ main.cpp
        ship.h
        ship.cpp
        events.h
        randomizerKod.h
        events.cpp)
