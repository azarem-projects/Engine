set(PROJECT_NAME debugging)

project(${PROJECT_NAME} VERSION 1.0.0)

file(GLOB DEBUGGING_SRC
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/**/*.cpp
)

include_directories(src/debugging)

add_library(${PROJECT_NAME} ${DEBUGGING_SRC})

target_link_libraries(${PROJECT_NAME} spdlog)
target_include_directories(${PROJECT_NAME} PRIVATE ../../external/spdlog-1.x/include)