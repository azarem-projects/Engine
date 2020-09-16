# The main CMake file. Its scope is the entire solution.

cmake_minimum_required(VERSION 3.16)

# Global variables.
set(PROJECT_NAME        Engine)
set(EXTERNAL_FOLDER     external)
set(PACKAGES_FOLDER     packages)

set(GLEW_PATH               ${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_FOLDER}/glew-2.1.0/build/cmake)
set(GLEW_INCLUDE_DIR        ${EXTERNAL_FOLDER}/glew-2.1.0/include)
set(GLFW_PATH               ${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_FOLDER}/glfw-3.3.2)
set(GLFW_INCLUDE_DIR        ${GLFW_PATH}/include)
set(ASSIMP_PATH             ${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_FOLDER}/assimp-5.0.0)
set(ASSIMP_INCLUDE_DIR      ${ASSIMP_PATH}/include)
set(SPDLOG_PATH             ${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_FOLDER}/spdlog-1.x)
set(SPDLOG_INCLUDE_DIR      ${SPDLOG_PATH}/include)
set(GLM_PATH                ${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_FOLDER}/glm-0.9.9.8)
set(GLM_INCLUDE_DIR         ${GLM_PATH})
set(MATH_PATH               ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGES_FOLDER}/math)
set(MATH_INCLUDE_DIR        ${MATH_PATH}/include)
set(ASSETS_PATH             ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGES_FOLDER}/assets)
set(ASSETS_INCLUDE_DIR      ${ASSETS_PATH}/include)
set(DEBUG_PATH              ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGES_FOLDER}/debug)
set(DEBUG_INCLUDE_DIR       ${DEBUG_PATH}/include)
set(FILES_PATH              ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGES_FOLDER}/files)
set(FILES_INCLUDE_DIR       ${FILES_PATH}/include)
set(STB_IMAGE_PATH          ${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_FOLDER}/stb_image)
set(STB_IMAGE_INCLUDE_DIR   ${STB_IMAGE_PATH}/include)

set(GLFW_BUILD_DOCS         OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS        OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES     OFF CACHE BOOL "" FORCE)

include_directories(${MATH_INCLUDE_DIR})
include_directories(${DEBUG_INCLUDE_DIR})
include_directories(${ASSETS_INCLUDE_DIR})

project(${PROJECT_NAME})

# Add external dependencies as child cmake-projects.
add_subdirectory(${GLEW_PATH})
add_subdirectory(${GLFW_PATH})
add_subdirectory(${ASSIMP_PATH})
add_subdirectory(${SPDLOG_PATH})
add_subdirectory(${MATH_PATH})
add_subdirectory(${ASSETS_PATH})
add_subdirectory(${DEBUG_PATH})
add_subdirectory(${FILES_PATH})
add_subdirectory(${STB_IMAGE_PATH})
add_subdirectory(${GLM_PATH})

# Add engine projects as child cmake-projects.
add_subdirectory(${PROJECT_SOURCE_DIR}/api)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)