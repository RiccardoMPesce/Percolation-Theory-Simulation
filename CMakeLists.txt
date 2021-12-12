cmake_minimum_required(VERSION 3.0.0)
project(PercolationTheorySimulation VERSION 1.0)

# This is where our .cpp and .h files are located
include_directories(app/services/cpp/)
file(GLOB SOURCES "app/services/cpp/*.cpp")

# This is our executable file
add_executable(main ${SOURCES})
