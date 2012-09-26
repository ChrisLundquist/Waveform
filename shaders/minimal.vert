#version 150

uniform transform
{
    mat4 MVP;
} Transform;

in vec3 in_Position;
in vec4 in_Color;

out vec4 v_Color;

void main() {
    v_Color = in_Color;
    gl_Position = Transform.MVP * vec4(in_Position, 1.0);
}
