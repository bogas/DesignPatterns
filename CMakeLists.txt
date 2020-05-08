cmake_minimum_required(VERSION 3.15)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(DesignPatterns Adapter.cpp common_design.h testing.h)
target_link_libraries(DesignPatterns)