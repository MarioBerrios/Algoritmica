cmake_minimum_required(VERSION 3.10)
project(practica5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -lrt -O3")

add_executable(practica5 main.cpp funcionesMedioNivel.cpp comunes.cpp 
    funcionesBT.cpp funcionesVegas.cpp funcionesMontecarlo.cpp)