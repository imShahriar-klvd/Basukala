cmake_minimum_required (VERSION 3.22)
set(CMAKE_BUILD_TYPE Debug)

project(BasuKala LANGUAGES CXX)

# ------------------------------ Execution part ------------------------------------------------
# Include directories
include_directories(./include)

# Main executable
set(
    PROJECT_SOURCES
    main.cc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})