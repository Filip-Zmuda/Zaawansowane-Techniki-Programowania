cmake_minimum_required(VERSION 3.28)
project(watki)

set(CMAKE_CXX_STANDARD 17)

add_executable(watki main.cpp
        Counter.cpp
        Counter.h)
