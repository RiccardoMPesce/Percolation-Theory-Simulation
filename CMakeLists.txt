cmake_minimum_required(VERSION 3.0.0)
project(PercolationTheorySimulation VERSION 1.0)

# include_directories(app/services/cpp/)
# file(GLOB SOURCES "app/services/cpp/*.cpp")

# This is where our .cpp and .h files are located
set(PROJECT_SOURCE_DIR "app/services/cpp")
set(PROJECT_INCLUDE_DIR "app/services/cpp")

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/*.h
    ${PROJECT_SOURCE_DIR}/*.cpp
)

# This is our executable file
# add_executable(main ${SOURCES})
