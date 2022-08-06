## This is a standard CMakeLists.txt template, including
## how to enable C++11 compiler option and how to set 'Release'
## target compile option
 
cmake_minimum_required(VERSION 2.8)
project(LaneTracking)
############# Use message function to print information ############
message(STATUS "CMake version: ${CMAKE_VERSION}")
 
############ enable C++11 compiler###############
## Method 2
SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++17")
##set c++/c standard
SET(CMAKE_CXX_STANDARD 17)
##SET(CMAKE_C_STANDARD 17)
 
################## Some useful arguments ##########################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
##########
##Build###
##########
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)##add header files, needed while compiling
link_directories(${CMAKE_SOURCE_DIR}/lib)##add static link libraries path, needed while compiling, ".so" files
add_executable(Inference src/Inference.cpp)##create executable file, no suffixes
target_link_libraries(Inference tensorflow tensorflow_framework ${OpenCV_LIBS})#link executable file to dynamic libraries, needed while running, ".so2" files, same path with ".so" files
