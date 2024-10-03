add_executable(buried_example 
    buried_example.cpp
)

target_link_libraries(buried_example PRIVATE
    Buried_static
)
