#include "../include/VertexBuffer.h"
#include "../include/Renderer.h"


namespace mesh_viewer {
    VertexBuffer::VertexBuffer(const void *data, uint32_t size) {
        m_RendererID = 0;
        GLCall(glGenBuffers(1, &m_RendererID));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    VertexBuffer::~VertexBuffer() {
        GLCall(glDeleteBuffers(1, &m_RendererID));
    }

    void VertexBuffer::bind() const {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    }

    void VertexBuffer::unbind() {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }

}// namespace mesh_viewer