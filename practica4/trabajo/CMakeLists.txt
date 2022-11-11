cmake_minimum_required(VERSION 3.10)
project(practica4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -lrt -O3")

add_executable(practica4 main.cpp funcionesMedioNivel.cpp funcionesDinamica.cpp serietemporal.cpp 
recta.cpp punto.cpp)