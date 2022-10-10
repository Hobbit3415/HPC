cmake_minimum_required(VERSION 3.5)

project(LinealRegresion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Se crea una variable para las fuentes
set(project_sources
    main.cpp
    Extraction/extraction_data.cpp
    Regression/linearregression.cpp)

# Se crea una variable par alas interfaces
set(project_headers
    Extraction/extraction_data.h
    Regression/linearregression.h)

add_executable(${PROJECT_NAME}
               ${project_headers}
               ${project_sources})
