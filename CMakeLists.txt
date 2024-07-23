cmake_minimum_required(VERSION 3.28)
project(my_stl)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_stl main.cpp
        vector/my_vector.cpp
        vector/my_vector.h
        vector/my_vector_init.h)
