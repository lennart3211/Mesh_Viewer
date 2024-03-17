cmake_minimum_required(VERSION 3.26)
project(opengl)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/include")

set(GLFW_LIBRARY_STATIC "${PROJECT_SOURCE_DIR}/external/lib/libglfw3.a")
set(GLFW_LIBRARY_SHARED "${PROJECT_SOURCE_DIR}/external/lib/glfw3.dll")

set(GLEW_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/include")

set(GLEW_LIBRARY "${PROJECT_SOURCE_DIR}/external/lib/glew32s.lib")

find_package(OpenGL REQUIRED)

set(SOURCES
        src/main.cpp
        src/Application.cpp
        src/Application.h
        src/Renderer.cpp
        src/Renderer.h
        src/Error.h
        src/VertexBuffer.cpp
        src/VertexBuffer.h
        src/IndexBuffer.cpp
        src/IndexBuffer.h
        src/VertexArray.cpp
        src/VertexArray.h
        src/VertexBufferLayout.cpp
        src/VertexBufferLayout.h
        src/Shader.cpp
        src/Shader.h
        src/Vec4.h
        src/Vec2.h
        src/Vec3.h
        external/include/stb_image.h
        src/Texture.cpp
        src/Texture.h
)

add_executable(opengl ${SOURCES})

target_include_directories(opengl PRIVATE ${GLFW_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

target_link_libraries(opengl PRIVATE ${GLFW_LIBRARY_STATIC} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

add_custom_command(TARGET opengl POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLFW_LIBRARY_SHARED}"
        $<TARGET_FILE_DIR:opengl>)