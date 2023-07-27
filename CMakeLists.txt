cmake_minimum_required(VERSION 3.10)

project(slicer) # a 3d printing slicer

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SKIP_INSTALL_RULES True)
set(CMAKE_BINARY_DIR "./bin")



#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(test test.cpp)
add_executable(run main.cpp)

#target_link_libraries(test ${GTEST_LIBRARIES} pthread)
