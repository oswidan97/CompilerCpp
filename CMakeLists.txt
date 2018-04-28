cmake_minimum_required(VERSION 3.7)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp tokenizer.cpp tokenizer.h TokenSchemer.cpp TokenSchemer.h)
add_executable(Compiler ${SOURCE_FILES})