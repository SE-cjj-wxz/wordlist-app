cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14) 

include_directories(include)

add_subdirectory("core")

add_executable(WordList main.cpp include/utils.h)

target_link_libraries(WordList core)