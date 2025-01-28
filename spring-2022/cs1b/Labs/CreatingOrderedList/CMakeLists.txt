cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cpp src/memory/createList.cpp 
               src/helpers/readInput.cpp src/helpers/insertNode.cpp
               src/helpers/placeNodeFront.cpp 
               src/helpers/placeNodeBack.cpp src/helpers/displayHeader.cpp
               src/handlers/handleNodePlacement.cpp
               src/handlers/handleDisplayList.cpp src/helpers/displayMenu.cpp
               src/handlers/isListEmpty.cpp src/handlers/searchName.cpp
               src/handlers/removeNode.cpp src/handlers/clearList.cpp
               src/handlers/validateInput.cpp src/handlers/handleSwitch.cpp
               src/helpers/heading.cpp)