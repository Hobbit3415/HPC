cmake_minimum_required(VERSION 3.5)

project(parcial03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Se crea una variable para las fuentes
set(project_sources
    main.cpp
    Extraction/extraction_data.cpp
    Regression/linear_regression.cpp)

# Se crea una variable para las interfaces
set(project_headers
    Extraction/extraction_data.h
    Regression/linear_regression.h)


add_executable(${PROJECT_NAME}
               ${project_headers}
               ${project_sources})

install(TARGETS parcial03
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
