cmake_minimum_required(VERSION 3.13)

project(JustTestIt)

add_library(jti)
target_include_directories(jti PUBLIC src)

add_executable(client)
target_link_libraries(client PRIVATE jti)

add_library(box-production)
add_executable(box-test)
target_link_libraries(box-test PRIVATE box-production)
target_link_libraries(box-test PRIVATE jti)

add_subdirectory(src)
add_subdirectory(example)