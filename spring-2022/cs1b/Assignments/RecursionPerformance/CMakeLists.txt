cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cpp src/print/menu.cpp src/print/heading.cpp
               src/handlers/factorial.cpp src/handlers/fibonacci.cpp 
               src/handlers/factorialPerformance.cpp 
               src/handlers/fibonacciPerformance.cpp src/handlers/switchLoop.cpp
               src/handlers/validation.cpp)