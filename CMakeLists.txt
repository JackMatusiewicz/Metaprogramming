cmake_minimum_required(VERSION 3.24.2)
project(JML CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(JML INTERFACE
        src/TypeList.h
        src/Map.h
        src/Aggregate.h
        src/HList.h
        src/ToType.h
        src/Concat.h
        src/Exists.h
        src/Count.h
        src/Repeat.h
        src/TypeMatch.h src/Unique.h src/BitSet.h src/Contains.h src/Subset.h)
