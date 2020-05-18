cmake_minimum_required(VERSION 3.15)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(DesignPatterns common_design.h Features/ReinterpretCast.cpp)
target_link_libraries(DesignPatterns)