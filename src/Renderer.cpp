#include "Renderer.h"

namespace mesh_viewer {

    void Renderer::draw(VertexArray *va, IndexBuffer *ib, Shader *shader) {
        shader->bind();
        va->bind();
        ib->bind();
        GLCall(glDrawElements(GL_TRIANGLES, ib->getCount(), GL_UNSIGNED_INT, nullptr));
    }
} // namespace mesh_viewer