cmake_minimum_required(VERSION 3.5)

project(eigen01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(eigen01 main.cpp)

install(TARGETS eigen01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
