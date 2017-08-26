cmake_minimum_required(VERSION 3.6)
project(Laberinto)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp MazeGenerator.h LaberintoSolver.cpp LaberintoSolver.h MazeGenerator.cpp)
add_executable(Laberinto ${SOURCE_FILES})
target_link_libraries(Laberinto Qt5::Widgets)