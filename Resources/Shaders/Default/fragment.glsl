#version 430 core

in vec2 out_Uv;

out vec4 out_Color;

uniform sampler2D u_Texture;

void main()
{
    out_Color = texture(u_Texture, out_Uv);
    // out_Color = vec4(1, 1, 0, 1);
}
