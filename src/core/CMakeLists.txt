cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DF_PIC)
include_directories(../include)

aux_source_directory(. SRC)

add_library(core SHARED ${SRC})