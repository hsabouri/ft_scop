#version 410

layout(location=0) in	vec4 vPos;
layout(location=1) in	vec4 vCol;

out						vec4 ex_Color;

void main(void)
{
	gl_Position = vPos;
	ex_Color = vec4(1, 0, 0, 1);
}
