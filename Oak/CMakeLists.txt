# based off of code from Neomer and tobanteGaming
# https://github.com/TheCherno/Hazel/pull/236/files
# https://github.com/TheCherno/Hazel/pull/1/files

cmake_minimum_required(VERSION 3.14)
project(Oak)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(OAK_DEBUG)

include_directories(vendor/spdlog/include)
#[[
include_directories(vendor/Glad/include)
include_directories(vendor/GLFW/include)
include_directories(vendor/imgui)
include_directories(vendor/stb_image)
include_directories(vendor/glm)

add_subdirectory(vendor/glm)
add_subdirectory(vendor/GLFW)
]]

#[[
set(IMGUI_SRC
        vendor/imgui/imgui.h
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/imgui/imgui_demo.cpp
        vendor/imgui/imgui_draw.cpp)

set(STBIMG_SRC
        vendor/stb_image/stb_image.cpp)

set(GLAD_SRC
        vendor/Glad/src/glad.c)
]]

set(SOURCES
        src/Oak/Application.cpp
        src/Oak/Application.h
        src/Oak/Core.h
        src/Oak/EntryPoint.h
#[[
        src/Oak/Core/Input.cpp
        src/Oak/Core/Input.h
        src/Oak/Core/KeyCodes.h
        src/Oak/Core/Layer.cpp
        src/Oak/Core/Layer.h
        src/Oak/Core/LayerStack.cpp
        src/Oak/Core/LayerStack.h
]]
        src/Oak/Log.cpp
        src/Oak/Log.h
#[[
        src/Oak/Core/MouseCodes.h
        src/Oak/Core/Timestep.h
        src/Oak/Core/Window.cpp
        src/Oak/Core/Window.h
        src/Oak/Debug/Instrumentor.h
        src/Oak/Events/ApplicationEvent.h
        src/Oak/Events/Event.h
        src/Oak/Events/KeyEvent.h
        src/Oak/Events/MouseEvent.h
        src/Oak/ImGui/ImGuiBuild.cpp
        src/Oak/ImGui/ImGuiLayer.cpp
        src/Oak/ImGui/ImGuiLayer.h
        src/Oak/Renderer/Buffer.cpp
        src/Oak/Renderer/Buffer.h
        src/Oak/Renderer/GraphicsContext.cpp
        src/Oak/Renderer/GraphicsContext.h
        src/Oak/Renderer/OrthographicCamera.cpp
        src/Oak/Renderer/OrthographicCamera.h
        src/Oak/Renderer/OrthographicCameraController.cpp
        src/Oak/Renderer/OrthographicCameraController.h
        src/Oak/Renderer/RenderCommand.cpp
        src/Oak/Renderer/RenderCommand.h
        src/Oak/Renderer/Renderer.cpp
        src/Oak/Renderer/Renderer.h
        src/Oak/Renderer/Renderer2D.cpp
        src/Oak/Renderer/Renderer2D.h
        src/Oak/Renderer/RendererAPI.cpp
        src/Oak/Renderer/RendererAPI.h
        src/Oak/Renderer/Shader.cpp
        src/Oak/Renderer/Shader.h
        src/Oak/Renderer/Texture.cpp
        src/Oak/Renderer/Texture.h
        src/Oak/Renderer/VertexArray.cpp
        src/Oak/Renderer/VertexArray.h
        src/Platform/OpenGL/OpenGLBuffer.cpp
        src/Platform/OpenGL/OpenGLBuffer.h
        src/Platform/OpenGL/OpenGLContext.cpp
        src/Platform/OpenGL/OpenGLContext.h
        src/Platform/OpenGL/OpenGLRendererAPI.cpp
        src/Platform/OpenGL/OpenGLRendererAPI.h
        src/Platform/OpenGL/OpenGLShader.cpp
        src/Platform/OpenGL/OpenGLShader.h
        src/Platform/OpenGL/OpenGLTexture.cpp
        src/Platform/OpenGL/OpenGLTexture.h
        src/Platform/OpenGL/OpenGLVertexArray.cpp
        src/Platform/OpenGL/OpenGLVertexArray.h
        src/Platform/Windows/WindowsInput.cpp
        src/Platform/Windows/WindowsInput.h
        src/Platform/Windows/WindowsWindow.cpp
        src/Platform/Windows/WindowsWindow.h
]]

        src/Oak.h
#        src/hzpch.cpp
#        src/hzpch.h
        )


#add_library(${PROJECT_NAME} STATIC ${SOURCES} ${IMGUI_SRC} ${GLAD_SRC} ${STBIMG_SRC})
add_library(${PROJECT_NAME} STATIC ${SOURCES})

#target_link_libraries(${PROJECT_NAME} glfw) 

# Platform specific preprocessor defines
# PUBLIC  = define is visible to the user of Oak
# PRIVATE = define is visible Oak only
if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC OAK_PLATFORM_WINDOWS=1)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OAK_BUILD_DLL=1)
endif()
if(APPLE)
    # for MacOS X or iOS, watchOS, tvOS (since 3.10.3)
    target_compile_definitions(${PROJECT_NAME} PUBLIC OAK_PLATFORM_APPLE=1)
endif()
if(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
    target_compile_definitions(${PROJECT_NAME} PUBLIC OAK_PLATFORM_UNIX=1)
endif()


#include_directories(src)
# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/Oak)