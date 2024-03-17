#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "glm/fwd.hpp"

namespace mesh_viewer {
    class Shader {
    private:
        std::unordered_map<std::string, int> m_UniformLocationCache;
        std::string m_VertexPath;
        std::string m_FragmentPath;
        uint32_t m_RendererID;

    public:
        Shader(std::string vertexPath, std::string fragmentPath);
        ~Shader();

        void bind() const;
        void unbind() const;

        void setUniform4f(const std::string &name, const Vec4 &v);
        static void setUniform4f(uint32_t location, const Vec4 &v);
        void setUniform3f(const std::string &name, const Vec3 &v);
        void setUniform2f(const std::string &name, const Vec2 &v);
        static void setUniform2f(uint32_t location, const Vec2 &v);
        void setUniform1f(const std::string &name, float v);
        void setUniform1i(const std::string &name, int32_t v);
        void setUniformMat4f(const std::string &name, const glm::mat4 &matrix);

    private:
        uint32_t createShader(const std::string &vertexPath, const std::string &fragmentPath);
        static uint32_t compileShader(uint32_t type, const std::string &source);
        static std::string readFile(const std::string &filePath);

        uint32_t getUniformLocation(const std::string &name);
    };
}
