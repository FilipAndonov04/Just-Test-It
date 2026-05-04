target_sources(jti PRIVATE
    Test.h
    Test.cpp
    Asserts.h
    EntryPoint.h
)

add_subdirectory(Exception)
add_subdirectory(Impl)