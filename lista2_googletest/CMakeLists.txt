cmake_minimum_required(VERSION 3.26)
project(lista2_googletest)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista2_googletest main.cpp)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${googletest_SOURCE_DIR}/googletest/include)

target_link_libraries(lista2_googletest gtest_main)