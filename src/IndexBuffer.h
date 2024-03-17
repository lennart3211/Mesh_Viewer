#pragma once

#include <cstdint>

namespace mesh_viewer {

    class IndexBuffer {
    private:
        uint32_t m_RendererID;
        uint32_t m_Count;

    public:
        IndexBuffer(const uint32_t *data, uint32_t count);
        ~IndexBuffer();

        void bind() const;
        static void unbind();

        [[nodiscard]] inline uint32_t getCount() const { return m_Count; }
    };

}// namespace mesh_viewer

