cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)
project("wordlist")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

add_subdirectory("src")