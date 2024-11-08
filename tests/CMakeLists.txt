find_package(GTest CONFIG REQUIRED)

set(TEST_SRCS
    test.cpp
)

add_executable(UNIT_TEST
    ${TEST_SRCS}
)

target_link_libraries(UNIT_TEST PRIVATE
    GTest::gtest
)
