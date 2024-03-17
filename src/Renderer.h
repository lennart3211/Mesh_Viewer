#pragma once

#include "Error.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace mesh_viewer {
    class Renderer {
    private:

    public:
        static void draw(VertexArray *va, IndexBuffer *ib, Shader *shader) ;
    };
} // namespace mesh_viewer
