cmake_minimum_required(VERSION 3.27)
project(laba2 CXX)

set(CMAKE_C_STANDARD 11)

add_executable(laba2 main.cpp
        UI.h
        UI.cpp
        DynamicArray.hpp
        DynamicArray.h
        LinkedList.cpp
        LinkedList.h
        ListSequence.cpp
        ListSequence.h
        ArraySequence.cpp
        ArraySequence.h
        Sequence.h)
