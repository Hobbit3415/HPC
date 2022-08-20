cmake_minimum_required(VERSION 3.5)

project(Algebra01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Algebra01 main.cpp)

install(TARGETS Algebra01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
