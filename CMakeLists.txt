cmake_minimum_required(VERSION 3.13)

project(JustTestIt)

# Library
add_library(jti)
target_include_directories(jti PUBLIC include PRIVATE src)

add_subdirectory(src)

# Examples
add_subdirectory(example)