cmake_minimum_required(VERSION 3.26)
project(lista_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista_2 main.cpp)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)