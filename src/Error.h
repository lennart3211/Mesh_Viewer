#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include <cassert>

#define GLCall(x) glClearError(); x; assert(glCheckError())

namespace mesh_viewer {
    static inline void glClearError() {
        while (glGetError());
    }

    static inline bool glCheckError() {
        if (GLenum error = glGetError()) {
            std::cerr << "[OpenGL Error] {" << error << ")" << std::endl;
            return false;
        }
        return true;
    }
} // namespace mesh_viewer