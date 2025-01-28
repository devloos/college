cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/heading.cpp src/coinFlip.cpp src/averageLogic.cpp src/outputResults.cpp src/userInformation.cpp)
target_include_directories(main PUBLIC /include)