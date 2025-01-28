cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cpp src/handlers/classHeading.cpp
               src/handlers/printMenu.cpp src/handlers/validation.cpp
               src/namespaces/Animal.cpp src/handlers/printSetMenu.cpp
               src/handlers/validateBounds.cpp src/handlers/switchLoop.cpp)