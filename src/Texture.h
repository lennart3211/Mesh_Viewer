#pragma once

#include "Renderer.h"

namespace mesh_viewer {
    class Texture {
    private:
        uint32_t m_RendererID;
        std::string m_FilePath;
        uint8_t *m_LocalBuffer;
        int m_Width, m_Height, m_BPP;

    public:
        Texture(const std::string &path);
        ~Texture();

        void bind(uint32_t slot = 0) const;
        void unbind() const;

        [[nodiscard]] inline uint32_t getWidth()  const { return m_Width; }
        [[nodiscard]] inline uint32_t getHeight() const { return m_Height; }
    };
} // namespace mesh_viewer
