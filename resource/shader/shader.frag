#version 450 core

out vec4 color;

in vec2 v_TexCoord;

layout (location = 0) uniform vec4 u_Color;
layout (location = 1) uniform vec2 u_ScreenDimensions;
layout (location = 2) uniform sampler2D u_Texture;

void main() {
    color = texture(u_Texture, v_TexCoord);

}
