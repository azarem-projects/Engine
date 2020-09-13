# The main CMake file. Its scope is the entire solution.

cmake_minimum_required(VERSION 3.16)

# Global variables.
set(PROJECT_NAME        Engine)
set(EXTERNAL_FOLDER     external)

set(GLEW_PATH           ${EXTERNAL_FOLDER}/glew-2.1.0/build/cmake)
set(GLEW_INCLUDE_DIR    ${EXTERNAL_FOLDER}/glew-2.1.0/include)

set(GLFW_PATH           ${EXTERNAL_FOLDER}/glfw-3.3.2)
set(GLFW_INCLUDE_DIR    ${EXTERNAL_FOLDER}/glfw-3.3.2/include)

set(ASSIMP_PATH         ${EXTERNAL_FOLDER}/assimp-5.0.0)
set(ASSIMP_INCLUDE_DIR  ${EXTERNAL_FOLDER}/assimp-5.0.0/include)

set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

project(${PROJECT_NAME})

# Add external dependencies as child cmake-projects.
add_subdirectory(${PROJECT_SOURCE_DIR}/${GLEW_PATH})
add_subdirectory(${PROJECT_SOURCE_DIR}/${GLFW_PATH})
add_subdirectory(${PROJECT_SOURCE_DIR}/${ASSIMP_PATH})

# Add engine projects as child cmake-projects.
add_subdirectory(${PROJECT_SOURCE_DIR}/api)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)