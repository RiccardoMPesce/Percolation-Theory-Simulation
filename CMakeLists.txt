cmake_minimum_required(VERSION 3.4)
project(percolation_theory_simulation)

include_directories(${PROJECT_SOURCE_DIR}/app/services/cpp)
add_subdirectory(extern/pybind11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "app/services/")

pybind11_add_module(
    wrap SHARED
    app/services/cpp/wrap.cpp
    app/services/cpp/MonteCarlo.cpp
    app/services/cpp/Percolation.cpp
    app/services/cpp/WeightedQuickUnionUF.cpp
)

