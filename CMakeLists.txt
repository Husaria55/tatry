cmake_minimum_required(VERSION 3.31)
project(tatry)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(tatry main.cpp Graph.cpp)

file(COPY szlaki.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})