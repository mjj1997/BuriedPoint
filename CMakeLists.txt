cmake_minimum_required(VERSION 3.20)

project(PROJECT_NAME VERSION 1.1.1.1 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "build shared library" ON)
option(BUILD_STATIC_LIBS "build static library" ON)

option(BUILD_EXAMPLES "build examples" OFF)
option(BUILD_TESTS "build unit tests" OFF)

if (MSVC)
    set(LIBS ${LIBS} winmm iphlpapi ws2_32 dbghelp Kernel32)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_WIN32_WINNT=0x0601")
else()
    set(LIBS ${LIBS} dl pthread)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

include_directories(${CMAKE_SOURCE_DIR})

message(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

