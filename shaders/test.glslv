#version 410

in vec4 	vCol;
in vec4 	vPos;
in vec2 	vTex;

out vec4	color;
out vec2	tex;

uniform	mat4	View;
uniform	mat4	Model;
uniform mat4	Proj;

void main(void)
{
	gl_Position = (Proj * View * Model) * vPos;
	color = vCol;
	tex = vTex;
}
