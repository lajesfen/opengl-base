cmake_minimum_required(VERSION 3.28)

# -----------------------------
# Project setup
# -----------------------------
project(Base LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")

# -----------------------------
# External Libraries
# -----------------------------
set(EXTERNAL_DIR "${PROJECT_SOURCE_DIR}/external")

# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
add_subdirectory("${EXTERNAL_DIR}/glfw")

# GLAD
add_library(glad STATIC "${EXTERNAL_DIR}/glad/src/gl.c")
target_include_directories(glad PUBLIC "${EXTERNAL_DIR}/glad/include")

# GLM
add_subdirectory("${EXTERNAL_DIR}/glm")

# -----------------------------
# Executable
# -----------------------------
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
        src/main.cpp
        src/program.cpp
        src/shader.cpp
        src/resource_manager.cpp
        src/texture.cpp
        src/window.cpp

        src/config.h
        src/utils/filesystem.h
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_include_directories(${PROJECT_NAME} PUBLIC
        "${EXTERNAL_DIR}/glm"
        "${EXTERNAL_DIR}/glad/include"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCES="${PROJECT_SOURCE_DIR}/resources")

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad glm::glm OpenGL::GL)
