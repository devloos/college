cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)

add_executable(
  ${PROJECT_NAME} src/core/Main.cpp src/utility/Utility.cpp src/core/HW01.cpp
  src/views/Menu.cpp src/components/DetCost.cpp src/views/Info.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC /include)

# Letting CMake find library
# find_library(${LIB_NAME} ${LIB_TO_FIND} PATHS /tmp/customPath)
# User explicitly finding library
# target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_HEADER_FILES})
# target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_TO_INCLUDE})
