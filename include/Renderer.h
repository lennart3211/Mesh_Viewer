#pragma once

#include "Error.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"

namespace mesh_viewer {
    class Renderer {
    private:

    public:
        static void draw(VertexArray *va, IndexBuffer *ib, Shader *shader) ;
    };
} // namespace mesh_viewer
