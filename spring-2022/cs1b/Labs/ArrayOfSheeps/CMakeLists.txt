cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)
add_executable(${PROJECT_NAME} src/main.cpp src/Sheep.cpp src/handlers/menu.cpp
               src/handlers/headerClass.cpp src/SheepList.cpp
               src/SheepLinkedList.cpp src/handlers/validateInt.cpp)