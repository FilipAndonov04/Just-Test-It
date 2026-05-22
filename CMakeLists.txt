cmake_minimum_required(VERSION 3.13)

project(JustTestIt)

add_library(jti)
target_include_directories(jti PUBLIC include PRIVATE src)

add_executable(usage-examples)
target_link_libraries(usage-examples PRIVATE jti)

add_library(box-production)
add_executable(box-test)
target_link_libraries(box-test PRIVATE box-production)
target_link_libraries(box-test PRIVATE jti)

add_subdirectory(src)
add_subdirectory(example)