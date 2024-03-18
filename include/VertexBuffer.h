#pragma once

#include <cstdint>

namespace mesh_viewer {

    class VertexBuffer {
    private:
        uint32_t m_RendererID = 0;

    public:
        VertexBuffer(const void *data, uint32_t size);
        ~VertexBuffer();

        void bind() const;
        static void unbind();
    };

}// namespace mesh_viewer

