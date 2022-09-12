cmake_minimum_required(VERSION 3.5)

project(LinealRegresion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinealRegresion main.cpp)

install(TARGETS LinealRegresion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Se debe crear una variable para agregar la
# direccion en donde se encuentre la clase
# Extraccion
#Extraccion/extraction.h
#Extraccion/extraction.cpp
