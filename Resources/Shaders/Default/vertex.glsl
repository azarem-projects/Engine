#version 430 core

in vec3 position;
in vec2 uv;

out vec2 out_Uv;

uniform mat4 u_Projection;
// uniform mat4 u_View;
uniform mat4 u_Model;

void main()
{
    // gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0);
    gl_Position = u_Projection * u_Model * vec4(position, 1.0);
    out_Uv = uv;
}
