cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME api)

file(GLOB API_SRC
    src/*.cpp
    src/**/*.cpp
)

add_library(${PROJECT_NAME} ${API_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${ASSIMP_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} glew_s)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} assimp)