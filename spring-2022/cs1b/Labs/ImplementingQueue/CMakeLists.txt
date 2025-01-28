cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)
add_executable(main
    src/main.cpp
    src/heading.cpp
    src/displayMenu.cpp
    src/push&pop.cpp
    src/validateInput.cpp
    src/isEmpty.cpp
    src/front.cpp
    src/switchCase.cpp
    src/deallocate.cpp
    src/clearQueue.cpp
)