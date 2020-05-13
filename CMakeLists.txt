cmake_minimum_required(VERSION 3.15)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(DesignPatterns common_design.h Curiosities/SmartPointers.cpp)
target_link_libraries(DesignPatterns)