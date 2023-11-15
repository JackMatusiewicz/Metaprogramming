cmake_minimum_required(VERSION 3.26)
project(JML)

set(CMAKE_CXX_STANDARD 20)

add_library(JML SHARED
        src/TypeList.h
        src/Map.h
        src/Aggregate.h
        src/HList.h
        src/ToType.h
        src/empty.cpp)
