cmake_minimum_required(VERSION 3.24)
project(attempt)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 17)

add_executable(attempt main.cpp)
