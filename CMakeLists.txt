cmake_minimum_required(VERSION 4.2)
project(Test)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test src/main.cpp src/todo.cpp)
target_include_directories(Test PRIVATE include)
