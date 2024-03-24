cmake_minimum_required(VERSION 3.27)
project(lista1)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib/hello)
add_library(hello lib/hello/hello.cpp)

add_executable(P1 /home/filip/ztp-filip_zmuda/lista1/src/prog1)
add_executable(P2 /home/filip/ztp-filip_zmuda/lista1/src/prog2)
        
target_link_libraries(P1 PRIVATE hello)
target_link_libraries(P2 PRIVATE hello)

find_package(Threads REQUIRED)
target_compile_options(P1 PRIVATE -pthread)
target_link_libraries(P1 PRIVATE Threads::Threads)

include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/archive/v3.7.1.tar.gz
)
FetchContent_MakeAvailable(json)

target_link_libraries(P2 PRIVATE nlohmann_json::nlohmann_json)
