cmake_minimum_required(VERSION 3.26)
project(lista5)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista5 main.cpp
        CoolingSystem.cpp
        CoolingSystem.h
        CoolingSystemMock.cpp
        CoolingSystemMock.h
        NuclearReactor.cpp
        NuclearReactor.h
        FusionReactor.cpp
        FusionReactor.h
        AntimatterReactor.h)
