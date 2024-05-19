cmake_minimum_required(VERSION 3.26)
project(text_Lib_test)

set(CMAKE_CXX_STANDARD 23)

add_executable(main_text_lib_test_file main.cpp)

include_directories(Text_lib)
add_subdirectory(Text_lib)
message("Hello world from cmake")
target_link_libraries(main_text_lib_test_file text_lib)