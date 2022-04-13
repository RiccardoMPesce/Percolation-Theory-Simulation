cmake_minimum_required(VERSION 3.10)

project(percolation_theory_simulation)

include_directories(${PROJECT_SOURCE_DIR}/app/services/cpp)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
add_subdirectory(${PROJECT_SOURCE_DIR}/extern/pybind11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/app/services/)

pybind11_add_module(
    wrap MODULE
    ${PROJECT_SOURCE_DIR}/app/services/cpp/wrap.cpp
    ${PROJECT_SOURCE_DIR}/app/services/cpp/MonteCarlo.cpp
    ${PROJECT_SOURCE_DIR}/app/services/cpp/Percolation.cpp
    ${PROJECT_SOURCE_DIR}/app/services/cpp/WeightedQuickUnionUF.cpp
)

