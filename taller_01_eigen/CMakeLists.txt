cmake_minimum_required(VERSION 3.5)

project(taller_01_eigen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taller_01_eigen main.cpp)

install(TARGETS taller_01_eigen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
