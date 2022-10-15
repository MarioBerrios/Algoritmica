cmake_minimum_required(VERSION 3.10)
project(practica1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -lrt")

add_executable(practica1 main.cpp funtionality.cpp funcNlogN.cpp funcDetIt.cpp funcDetFact.cpp misc.cpp sistemaEcuaciones.cpp)