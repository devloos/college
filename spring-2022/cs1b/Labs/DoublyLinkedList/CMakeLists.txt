cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cc src/handlers/nodePlacement.cc
               src/helpers/insertNode.cc src/helpers/readInput.cc
               src/helpers/placeNodeBack.cc src/helpers/placeNodeFront.cc
               src/memory/createList.cc src/handlers/displayList.cc
               src/helpers/displayHeader.cc src/helpers/displayMenu.cc
               src/handlers/validateInput.cc src/handlers/removeNode.cc)