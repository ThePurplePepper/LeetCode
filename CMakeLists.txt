cmake_minimum_required(VERSION 4.0)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LeetCode
        main.cpp
        Problem.cpp
        Problem.h
        ProblemFactory.cpp
        ProblemFactory.h
        helperFunctions.h)
