#version 450 core

out vec4 color;

in vec2 v_TexCoord;

layout (location = 0) uniform vec4 u_Color;
layout (location = 1) uniform vec2 u_ScreenDimensions;
layout (location = 2) uniform sampler2D u_Texture;

void main() {
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor;
    color.r = u_Color.r;
//    color.r *= gl_FragCoord.x / u_ScreenDimensions.x;
//    color.b *= gl_FragCoord.y / u_ScreenDimensions.y;
}
