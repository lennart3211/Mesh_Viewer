#pragma once

namespace mesh_viewer {
    class Vec4 {
    public:
        Vec4() = default;
        inline Vec4(float x, float y, float z, float w)
            : x(x), y(y), z(z), w(w) {}

        float x, y, z, w;
        float &r = x, &g = y, &b = z, &a = w;
    };

} // namespace mesh_viewer