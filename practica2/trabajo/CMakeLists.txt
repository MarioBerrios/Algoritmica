cmake_minimum_required(VERSION 3.10)
project(practica2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -lrt")

add_executable(practica2 main.cpp funcionesMedioNivel.cpp funciones.cpp serietemporal.cpp recta.cpp punto.cpp)