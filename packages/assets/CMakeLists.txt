

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME assets)

file(GLOB ASSETS_SRC
    src/*.cpp
    src/**/*.cpp
)

add_library(${PROJECT_NAME} ${ASSETS_SRC})

target_link_libraries(${PROJECT_NAME} math)
target_link_libraries(${PROJECT_NAME} assimp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/assets)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${DEBUG_INCLUDE_DIR})