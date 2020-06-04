cmake_minimum_required(VERSION 3.14)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

include_directories(../Oak/vendor/spdlog/include)
#include_directories(../Oak/vendor/Glad/include)
#include_directories(../Oak/vendor/GLFW/include)
#include_directories(../Oak/vendor/imgui)
#include_directories(../Oak/vendor/stb_image)
#include_directories(../Oak/vendor/glm)


include_directories(../Oak/src)
#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

set(SOURCES
        #src/ExampleLayer.cpp
        #src/ExampleLayer.h
        #src/Sandbox2D.cpp
        #src/Sandbox2D.h
        ./src/SandboxApp.cpp
        ../Oak/src/Oak.h)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Oak)