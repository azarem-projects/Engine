set(PROJECT_NAME engine)

project(${PROJECT_NAME} VERSION 1.0.0)

file(GLOB ENGINE_SRC
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/**/*.cpp
)

add_executable(${PROJECT_NAME} ${ENGINE_SRC})

target_link_libraries(${PROJECT_NAME} api)

target_include_directories(${PROJECT_NAME} PRIVATE ../packages/api/src)