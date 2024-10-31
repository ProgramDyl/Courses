cmake_minimum_required(VERSION 3.29)
project(Courses)

set(CMAKE_CXX_STANDARD 20)

add_executable(Courses main.cpp
        Student.h
        Student.cpp)
