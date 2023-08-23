cmake_minimum_required(VERSION 3.27.3)
project(openglproj)

add_executable(${PROJECT_NAME} "src/main.cpp")
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

add_subdirectory(deps/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(deps/glad)
target_link_libraries(${PROJECT_NAME} glad)
