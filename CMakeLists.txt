cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Engine)
set(EXTERNAL_FOLDER external)

project(${PROJECT_NAME})

set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${PROJECT_SOURCE_DIR}/${EXTERNAL_FOLDER}/glew/build/cmake)
add_subdirectory(${PROJECT_SOURCE_DIR}/${EXTERNAL_FOLDER}/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/${EXTERNAL_FOLDER}/assimp)

add_subdirectory(${PROJECT_SOURCE_DIR}/api)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)