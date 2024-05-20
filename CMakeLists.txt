cmake_minimum_required(VERSION 3.26)

project(main)

set(LIB_NAME text_lib)
set(EXE_NAME text_main)

add_library(${LIB_NAME} "")
add_executable(${EXE_NAME} main.cpp)

add_subdirectory(text)

target_link_libraries(${EXE_NAME} ${LIB_NAME})
