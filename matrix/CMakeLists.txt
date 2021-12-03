cmake_minimum_required(VERSION 3.16)
project(matrix2)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(matrix2
        include/matrix.h
        src/matrix.cpp)