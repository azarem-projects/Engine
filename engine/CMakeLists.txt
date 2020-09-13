cmake_minimum_required(VERSION 3.16)

add_executable(engine src/main.cpp)

target_include_directories(engine PRIVATE ../external/glew/include)
target_include_directories(engine PRIVATE ../external/glfw/include)
target_include_directories(engine PRIVATE ../external/assimp/include)
target_include_directories(engine PRIVATE ../api/src)

target_link_libraries(engine glew_s)
target_link_libraries(engine glfw)
target_link_libraries(engine assimp)
target_link_libraries(engine api)