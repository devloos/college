cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)
add_executable(${PROJECT_NAME} src/main.cpp src/PersonType.cpp src/StudentType.cpp
               src/PersonTypeTestCases.cpp src/StudentTypeTestCases.cpp)