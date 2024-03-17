#include "Shader.h"
#include "Error.h"

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <utility>
#include <glm/gtc/type_ptr.hpp>

namespace mesh_viewer {
    Shader::Shader(std::string vertexPath, std::string fragmentPath)
        : m_VertexPath(std::move(vertexPath)), m_FragmentPath(std::move(fragmentPath)), m_RendererID(0) {
        m_RendererID = createShader(m_VertexPath, m_FragmentPath);
    }

    Shader::~Shader() {
        GLCall(glDeleteProgram(m_RendererID));
    }

    void Shader::bind() const {
        GLCall(glUseProgram(m_RendererID));
    }

    void Shader::unbind() const {
        GLCall(glUseProgram(0));
    }

    uint32_t Shader::compileShader(uint32_t type, const std::string &source) {
        GLCall(uint32_t id = glCreateShader(type));
        const char *src = &source[0];
        GLCall(glShaderSource(id, 1, &src, nullptr));
        GLCall(glCompileShader(id));

        int result;
        GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
        if (!result) {
            int length;
            GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
            char message[length];
            GLCall(glGetShaderInfoLog(id, length, &length, message));
            std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " Shader\n";
            std::cout << message << std::endl;
            GLCall(glDeleteShader(id));
            return 0;
        }

        return id;
    }

    uint32_t Shader::getUniformLocation(const std::string &name) {
        if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
            return m_UniformLocationCache[name];
        }

        GLCall(int32_t location = glGetUniformLocation(m_RendererID, name.c_str()));
        if (location < 0) {
            std::cout << "Warning: uniform " << name << " doesn't exist\n";
        }
        m_UniformLocationCache[name] = location;
        return location;
    }

    uint32_t Shader::createShader(const std::string &vertexPath, const std::string &fragmentPath) {
        const std::string &vertexShader = readFile(vertexPath);
        const std::string &fragmentShader = readFile(fragmentPath);

        GLCall(uint32_t program = glCreateProgram());
        uint32_t vs = compileShader(GL_VERTEX_SHADER, vertexShader);
        uint32_t fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

        GLCall(glAttachShader(program, vs));
        GLCall(glAttachShader(program, fs));
        GLCall(glLinkProgram(program));
        GLCall(glValidateProgram(program));

        GLCall(glDeleteShader(vs));
        GLCall(glDeleteShader(fs));

        return program;
    }

    std::string Shader::readFile(const std::string &filePath) {
        std::ifstream file(filePath);

        if (!file) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return "";
        }
        std::string content((std::istreambuf_iterator<char>(file)),
                            (std::istreambuf_iterator<char>()));

        return content;
    }

    void Shader::setUniform4f(const std::string &name, const Vec4 &v) {
        GLCall(glUniform4f(getUniformLocation(name), v.x, v.y, v.z, v.w));
    }

    void Shader::setUniform3f(const std::string &name, const Vec3 &v) {
        GLCall(glUniform3f(getUniformLocation(name), v.x, v.y, v.z));
    }

    void Shader::setUniform2f(const std::string &name, const Vec2 &v) {
        GLCall(glUniform2f(getUniformLocation(name), v.x, v.y));
    }

    void Shader::setUniform1f(const std::string &name, float v) {
        GLCall(glUniform1f(getUniformLocation(name), v));
    }

    void Shader::setUniform1i(const std::string &name, int32_t v) {
        GLCall(glUniform1i(getUniformLocation(name), v));
    }

    void Shader::setUniform4f(uint32_t location, const Vec4 &v) {
        GLCall(glUniform4f(location, v.x, v.y, v.z, v.w));
    }

    void Shader::setUniform2f(uint32_t location, const Vec2 &v) {
        GLCall(glUniform2f(location, v.x, v.y));
    }

    void Shader::setUniformMat4f(const std::string &name, const glm::mat4 &matrix) {
        GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, false, glm::value_ptr(matrix)));
    }


} // namespace mesh_viewer
