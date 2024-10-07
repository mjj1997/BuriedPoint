include_guard(GLOBAL)

include_directories(third_party/spdlog/include)

add_definitions(-DSPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)
add_subdirectory(third_party/spdlog)

set(BURIED_SRCS
    buried.cpp
    buried_core.cpp
)

set(MODULE_NAME "Buried")

message(STATUS "libs ${LIBS}")

if (BUILD_BURIED_SHARED_LIBS)
    add_library(${MODULE_NAME} SHARED ${BURIED_SRCS})
    target_link_libraries(${MODULE_NAME} PRIVATE ${LIBS} spdlog)
endif()

if (BUILD_BURIED_STATIC_LIBS)
    add_library(${MODULE_NAME}_static STATIC ${BURIED_SRCS})
    target_link_libraries(${MODULE_NAME}_static PRIVATE ${LIBS} spdlog)
endif()
