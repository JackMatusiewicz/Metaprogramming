cmake_minimum_required(VERSION 3.24.2)
project(JML)

set(CMAKE_CXX_STANDARD 20)

add_library(JML SHARED
        src/TypeList.h
        src/Map.h
        src/Aggregate.h
        src/HList.h
        src/ToType.h
        src/test.cpp
        src/Concat.h
        src/Exists.h
        src/Count.h
        src/Repeat.h
        src/TypeMatch.h src/Unique.h)
