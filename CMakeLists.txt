cmake_minimum_required(VERSION 3.24)
project(april)

set(CMAKE_CXX_STANDARD 17)

add_executable(april main.cpp Gronsfeld.cpp Gronsfeld.h)
