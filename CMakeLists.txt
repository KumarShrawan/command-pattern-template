cmake_minimum_required (VERSION 2.8.12)
project (CMakeHelloWorld)
set(CMAKE_CXX_STANDARD 14)
#version number
set (Central-Security-Manager_VERSION_MAJOR 1)
set (Central-Security-Manager_VERSION_MINOR 0)

add_definitions(-Wall -g -std=c++0x)
#include the subdirectory containing our libs
add_subdirectory (src)
include_directories(src)
#indicate the entry point for the executable
file(GLOB SOURCES "src/*.cpp")
add_executable (CentralSecurityManager main.cpp ${SOURCES})

# Indicate which libraries to include during the link process.
#target_link_libraries (CentralSecurityManager Hello)

install (TARGETS CentralSecurityManager DESTINATION bin)
