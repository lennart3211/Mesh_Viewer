#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace mesh_viewer {
    class Object3D {
    public:
        Object3D();
        ~Object3D();

    private:
        VertexBuffer *m_VertexBuffer;
        IndexBuffer  *m_IndexBuffer;

        float *m_Positions;
        uint32_t *m_Indices;
    };

}// namespace mesh_viewer

