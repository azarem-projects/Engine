cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME engine)
set(EXECUTABLE_NAME main)

file(GLOB ENGINE_SRC
    src/*.cpp
    src/**/*.cpp
)

add_executable(${EXECUTABLE_NAME} ${ENGINE_SRC})

target_include_directories(${EXECUTABLE_NAME} PRIVATE ../api/src)

target_link_libraries(${EXECUTABLE_NAME} api)