

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME files)

file(GLOB FILES_SRC
    src/*.cpp
    src/**/*.cpp
)

add_library(${PROJECT_NAME} ${FILES_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/files)
target_include_directories(${PROJECT_NAME} PRIVATE ${DEBUG_INCLUDE_DIR})