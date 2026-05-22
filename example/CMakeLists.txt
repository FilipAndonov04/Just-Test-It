add_executable(usage-examples)
target_link_libraries(usage-examples PRIVATE jti)

add_library(box-production)
add_executable(box-test)
target_link_libraries(box-test PRIVATE box-production)
target_link_libraries(box-test PRIVATE jti)

add_subdirectory(UsageExamples)
add_subdirectory(BoxClient)