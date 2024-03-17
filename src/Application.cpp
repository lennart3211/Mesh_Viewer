#include "Application.h"


namespace mesh_viewer {
    Application::Application() {
        initGLFW();
        initGLEW();

        m_Positions = new float[16];
        m_Positions[0]  = -0.5f; m_Positions[1]  = -0.5f; m_Positions[2]  =  0.0f; m_Positions[3]  =  0.0f;
        m_Positions[4]  =  0.5f; m_Positions[5]  = -0.5f; m_Positions[6]  =  1.0f; m_Positions[7]  =  0.0f;
        m_Positions[8]  =  0.5f; m_Positions[9]  =  0.5f; m_Positions[10] =  1.0f; m_Positions[11] =  1.0f;
        m_Positions[12] = -0.5f; m_Positions[13] =  0.5f; m_Positions[14] =  0.0f; m_Positions[15] =  1.0f;


        m_Indices = new uint32_t[6];
        m_Indices[0] = 0;
        m_Indices[1] = 1;
        m_Indices[2] = 2;
        m_Indices[3] = 2;
        m_Indices[4] = 3;
        m_Indices[5] = 0;

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


        m_VertexArray = new VertexArray();
        m_VertexBuffer = new VertexBuffer(m_Positions, 4 * 4 * sizeof(float));
        VertexBufferLayout m_VertexBufferLayout;
        m_VertexBufferLayout.push<float>(2);
        m_VertexBufferLayout.push<float>(2);
        m_VertexArray->addBuffer(m_VertexBuffer, &m_VertexBufferLayout);

        m_IndexBuffer = new IndexBuffer(m_Indices, 6);

        glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);

        m_Shader = new Shader("../resource/shader/shader.vert", "../resource/shader/shader.frag");
        m_Shader->bind();

        m_Shader->setUniform4f("u_Color", {1.0f, 0.5f, 1.0f, 1.0f});
        m_Shader->setUniform2f("u_ScreenDimensions", {float(width), float(height)});

        m_Shader->setUniformMat4f("u_MVP", proj);


//        m_Shader->setUniform3f("u_SpherePosition", Vec3(0, 0, 1));
//        m_Shader->setUniform1f("u_SphereRadius", 0.2f);
//        m_Shader->setUniform3f("u_LightDirection", Vec3(0.5, 1, -0.5));

        m_Texture = new Texture("../resource/texture/image.png");
        m_Texture->bind(0);
        m_Shader->setUniform1i("u_Texture", 0);

    }

    void Application::initGLFW() {
        glewExperimental = GL_TRUE;
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW.\n";
            exit(-1);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, "3D Mesh Viewer", nullptr, nullptr);
        if (!window) {
            glfwTerminate();
            exit(-1);
        }
        glfwMakeContextCurrent(window);
        std::cout << "Using OpenGL version " << glGetString(GL_VERSION) << std::endl;
    }

    void Application::initGLEW() {
        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize GLEW.\n";
            glfwTerminate();
            exit(-1);
        }
    }

    void Application::run() {
        float g = 0.0f;
        float increment = 0.001f;
        while (!glfwWindowShouldClose(window)) {
            GLCall(glClear(GL_COLOR_BUFFER_BIT));

            Renderer::draw(m_VertexArray, m_IndexBuffer, m_Shader);
            m_Shader->bind();
            glUniform4f(0, g, 0.5f, 1.0f, 1.0f);

            if (g > 1.0f) {
                increment = -0.001f;
            }
            if (g < 0.0f) {
                increment = 0.001f;
            }
            g += increment;

            GLCall(glfwSwapBuffers(window));
            GLCall(glfwPollEvents());
        }
    }

    Application::~Application() {
        delete m_VertexBuffer;
        delete m_IndexBuffer;
        delete m_VertexArray;
        delete m_Shader;
        delete m_Texture;

        delete[] m_Positions;
        delete[] m_Indices;

        glfwTerminate();
    }

}// namespace mesh_viewer