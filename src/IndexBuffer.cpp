#include "IndexBuffer.h"
#include "Renderer.h"

namespace mesh_viewer {
    IndexBuffer::IndexBuffer(const uint32_t *data, uint32_t count) : m_Count(count) {
            GLCall(glGenBuffers(1, &m_RendererID));
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
            GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW));
    }

    IndexBuffer::~IndexBuffer() {
    }

    void IndexBuffer::bind() const {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    }

    void IndexBuffer::unbind() {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

}// namespace mesh_viewer