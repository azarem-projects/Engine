cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME        Engine)
set(EXTERNAL_FOLDER     external)

set(GLEW_PATH           external/glew-2.1.0/build/cmake)
set(GLEW_INCLUDE_DIR    external/glew-2.1.0/include)

set(GLFW_PATH           external/glfw-3.3.2)
set(GLFW_INCLUDE_DIR    external/glfw-3.3.2/include)

set(ASSIMP_PATH         external/assimp-5.0.0)
set(ASSIMP_INCLUDE_DIR  external/assimp-5.0.0/include)

project(${PROJECT_NAME})

set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${PROJECT_SOURCE_DIR}/${GLEW_PATH})
add_subdirectory(${PROJECT_SOURCE_DIR}/${GLFW_PATH})
add_subdirectory(${PROJECT_SOURCE_DIR}/${ASSIMP_PATH})

add_subdirectory(${PROJECT_SOURCE_DIR}/api)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)