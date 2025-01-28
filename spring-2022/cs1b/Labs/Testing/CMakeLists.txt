cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cpp src/handleInput.cpp src/heading.cpp src/handleCalc.cpp src/handleOutput.cpp)
target_include_directories(main PUBLIC include/)