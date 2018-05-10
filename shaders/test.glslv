#version 410

in vec4 	vCol;
in vec4 	vPos;
in vec2 	vTex;

out vec4	color;
out vec2	tex;

uniform	mat4	View;
uniform	mat4	Model;
uniform mat4	Proj;
uniform int		TextureMode;

void main(void)
{
	gl_Position = (Proj * View * Model) * vPos;
	color = vCol;
	if (TextureMode == 0)
		tex = vTex;
	else if (TextureMode == 1)
		tex = vec2(vPos.z, vPos.y);
	else if (TextureMode == 2)
		tex = vec2(vPos.z, vPos.x);
	else
		tex = vec2(vPos.x, vPos.y);
}
