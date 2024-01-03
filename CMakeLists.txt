cmake_minimum_required(VERSION 3.24.2)
project(JML CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(JML INTERFACE
        src/TypeList.hpp
        src/Map.hpp
        src/Aggregate.hpp
        src/HList.hpp
        src/ToType.hpp
        src/Concat.hpp
        src/Exists.hpp
        src/Count.hpp
        src/Repeat.hpp
        src/TypeMatch.hpp
        src/Unique.hpp
        src/Bitset.hpp
        src/Contains.hpp
        src/Subset.hpp)

add_executable(executable src/main.cpp)
target_link_libraries(executable JML)
