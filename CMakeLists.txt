cmake_minimum_required(VERSION 3.29)
project(ClaudePOOProyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClaudePOOProyecto main.cpp
        Persona.cpp
        Persona.h
        Cliente.cpp
        Cliente.h
        Boleto.cpp
        Boleto.h
        BoletoVIP.cpp
        BoletoVIP.h)
