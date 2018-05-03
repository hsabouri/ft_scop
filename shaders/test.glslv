#version 410
#
attribute vec4 	vPos;
attribute vec4 	vCol;
varying vec4	color;

uniform	mat4	View;
uniform	mat4	Model;
uniform mat4	Proj;

void main(void)
{
	gl_Position = (Proj * View * Model) * vPos;
	color = vCol;
}
