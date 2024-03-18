#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Error.h"

namespace mesh_viewer {

    class VertexArray {
    private:
        uint32_t m_RendererID = 0;

    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(VertexBuffer *vb, VertexBufferLayout *layout) const;

        void bind() const;
        void unbind() const;

    };

}// namespace mesh_viewer
