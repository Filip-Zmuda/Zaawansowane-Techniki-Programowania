#!/usr/bin/bash
CXXFLAGS="-Ilib/hello"
g++ ${CXXFLAGS} -c ./src/prog1/main.cpp -o ./build/main.o
g++ ${CXXFLAGS} -c ./src/prog2/main2.cpp -o ./build/main2.o
g++ ${CXXFLAGS} -c ./lib/hello/hello.cpp -o ./build/hello.o
g++ ./build/main.o ./build/hello.o -o ./build/p1
g++ ./build/main2.o ./build/hello.o -o ./build/p2
