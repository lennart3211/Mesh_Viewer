#include "../include/Object3D.h"
#include <cstdlib>

namespace mesh_viewer {
    Object3D::Object3D() {
        const int pos_size = 8 * sizeof(float);

        m_Positions = (float *)malloc(pos_size);
        m_Positions[0] = -0.5f; m_Positions[1] = -0.5f;
        m_Positions[2] =  0.5f; m_Positions[3] = -0.5f;
        m_Positions[4] =  0.5f; m_Positions[5] =  0.5f;
        m_Positions[6] = -0.5f; m_Positions[7] =  0.5f;

        m_VertexBuffer = new VertexBuffer(m_Positions, pos_size);
        
        const int indices_size = 6 * sizeof(uint32_t);
        m_Indices = (uint32_t *)malloc(indices_size);
        
        m_Indices[0] = 0;
        m_Indices[1] = 1;
        m_Indices[2] = 2;
        m_Indices[3] = 2;
        m_Indices[4] = 3;
        m_Indices[5] = 0;

        m_IndexBuffer = new IndexBuffer(m_Indices, 6);
    }

    Object3D::~Object3D() {
        delete m_VertexBuffer;
        delete m_IndexBuffer;

        delete[] m_Positions;
        delete[] m_Indices;
    }
}// namespace mesh_viewer