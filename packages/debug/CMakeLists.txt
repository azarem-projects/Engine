

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME debug)

file(GLOB DEBUG_SRC
    src/*.cpp
    src/**/*.cpp
)

add_library(${PROJECT_NAME} ${DEBUG_SRC})

target_link_libraries(${PROJECT_NAME} spdlog)

target_include_directories(${PROJECT_NAME} PRIVATE ../../spdlog-1.x/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/debug)