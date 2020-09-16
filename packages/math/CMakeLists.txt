

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME math)

file(GLOB MATH_SRC
    src/*.cpp
    src/**/*.cpp
)

add_library(${PROJECT_NAME} ${MATH_SRC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/math)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)