cmake_minimum_required(VERSION 3.26)
project(op2_lab4_12)

set(CMAKE_CXX_STANDARD 20)

add_executable(op2_lab4_12 main.cpp
        figures/Rectangle.cpp
        figures/Rectangle.h
        figures/Trapezoid.cpp
        figures/Trapezoid.h
        Figures.cpp
        Figures.h
        Figure.h)
