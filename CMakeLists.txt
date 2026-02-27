cmake_minimum_required (VERSION 3.22)
set(CMAKE_BUILD_TYPE Debug)

project(BasuKala LANGUAGES CXX)

# ------------------------------ Execution part ------------------------------------------------
# Include directories
include_directories(./include)

# Main executable
set(
    PROJECT_SOURCES
    src/main.cc
    src/bsd.cpp
    src/cityStructure.cc
    src/hash.cpp
    src/maxheap.cpp
    src/model.cc
    src/oerder.cpp
    src/product.cpp
    src/user.cpp

)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})