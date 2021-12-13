cmake_minimum_required(VERSION 3.4)
project(percolation_theory_simulation)

add_subdirectory(extern/pybind11)

include_directories(${PROJECT_SOURCE_DIR}/app/services/cpp)

pybind11_add_module(wrap app/services/cpp/wrap.cpp)