#pragma once

namespace mesh_viewer {
    class Vec3 {
    public:
        Vec3() = default;
        inline Vec3(float x, float y, float z)
            : x(x), y(y), z(z) {}

        float x, y, z;
        float &r = x, &g = y, &b = z;
    };

} // namespace mesh_viewer