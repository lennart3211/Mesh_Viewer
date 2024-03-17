#pragma once

#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace mesh_viewer {

    class Application {
    public:
        Application();
        ~Application();

        void initGLFW();
        static void initGLEW();

        void run();


    private:
        GLFWwindow *window;
        const uint16_t width = 1920;
        const uint16_t height = 1080;

        uint32_t buffer;

        VertexArray *m_VertexArray;
        VertexBuffer *m_VertexBuffer;
        IndexBuffer  *m_IndexBuffer;
        Shader *m_Shader;
        Texture *m_Texture;
        float *m_Positions;
        uint32_t *m_Indices;

        uint32_t shader;
    };

}// namespace mesh_viewer
