cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME engine)

file(GLOB ENGINE_SRC
    src/*.cpp
    src/**/*.cpp
)

add_executable(engine ${ENGINE_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ../api/src)

target_link_libraries(${PROJECT_NAME} api)