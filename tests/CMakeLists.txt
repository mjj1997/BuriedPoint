cmake_minimum_required(VERSION 3.20)

project(BuriedTest)

set(TEST_SRCS
    test.cpp
)

add_executable(buried_test ${TEST_SRCS})
target_link_libraries(buried_test PRIVATE Buried_static gtest)
