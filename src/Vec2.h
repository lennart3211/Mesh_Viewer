#pragma once

namespace mesh_viewer {
    class Vec2 {
    public:
        Vec2() = default;
        inline Vec2(float x, float y)
            : x(x), y(y) {}

        float x, y;
    };

} // namespace mesh_viewer