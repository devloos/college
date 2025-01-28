cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cpp src/heading.cpp src/balanceIndex.cpp src/readFile.cpp src/searchName.cpp src/sumofBalances.cpp src/handleOutput.cpp src/handleSearchOutput.cpp)