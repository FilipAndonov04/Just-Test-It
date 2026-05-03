target_sources(jti PRIVATE
    Test.h
    Test.cpp
    Asserts.h
    EntryPoint.h
)

add_subdirectory(Impl)
add_subdirectory(Logging)
add_subdirectory(Exception)