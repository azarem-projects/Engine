set(PROJECT_NAME api)

project(${PROJECT_NAME} VERSION 1.0.0)

file(GLOB API_SRC
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/**/*.cpp
)

include_directories(src)

add_library(${PROJECT_NAME} ${API_SRC})

target_link_libraries(${PROJECT_NAME} debugging)
target_link_libraries(${PROJECT_NAME} glew_s)
target_link_libraries(${PROJECT_NAME} glfw)
target_include_directories(${PROJECT_NAME} PRIVATE ../../packages/debugging/src)