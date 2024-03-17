#pragma once

#include <cstdint>
#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <cassert>

namespace mesh_viewer {

    struct VertexBufferElement {
        uint32_t type;
        uint32_t count;
        bool normalized;

        static unsigned int getTypeSize(uint32_t type) {
            switch (type) {
                case GL_FLOAT:
                case GL_UNSIGNED_INT:  return 4;
                case GL_UNSIGNED_BYTE: return 1;
                default: assert(false);
            }
            return 0;
        }
    };

    class VertexBufferLayout {
    private:
        uint32_t m_Stride;
        std::vector<VertexBufferElement> m_Elements;

    public:
        VertexBufferLayout() : m_Stride(0) {}
        ~VertexBufferLayout() = default;

        template<typename T>
        void push(uint32_t count) { static_assert(false); }



        inline const std::vector<VertexBufferElement> &getElements() const { return m_Elements; }
        inline uint32_t getStride() const { return m_Stride; }

    };

    template<>
    inline void VertexBufferLayout::push<float>(uint32_t count) {
        m_Elements.push_back({GL_FLOAT, count, false});
        m_Stride += VertexBufferElement::getTypeSize(GL_FLOAT) * count;
    }

    template<>
    inline void VertexBufferLayout::push<uint32_t>(uint32_t count) {
        m_Elements.push_back({GL_UNSIGNED_INT, count, false});
        m_Stride += VertexBufferElement::getTypeSize(GL_UNSIGNED_INT) * count;
    }

    template<>
    inline void VertexBufferLayout::push<uint8_t>(uint32_t count) {
        m_Elements.push_back({GL_UNSIGNED_BYTE, count, true});
        m_Stride += VertexBufferElement::getTypeSize(GL_UNSIGNED_BYTE) * count;
    }

}// namespace mesh_viewer
