cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(
   main 
   src/main.cpp 
   src/readInput.cpp 
   src/dispMenu.cpp 
   src/validateInput.cpp 
   src/searchLogic.cpp 
   src/multiMoviePrint.cpp 
   src/subString.cpp 
   src/switchOption.cpp 
   src/printSingleMovie.cpp
   src/heading.cpp
   src/deallocate.cpp)