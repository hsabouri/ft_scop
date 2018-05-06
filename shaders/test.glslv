#version 410

attribute vec4 	vPos;
attribute vec4 	vCol;
attribute vec2 	vTex;

varying vec4	color;
varying vec2	tex;

uniform	mat4	View;
uniform	mat4	Model;
uniform mat4	Proj;

void main(void)
{
	gl_Position = (Proj * View * Model) * vPos;
	color = vCol;
	tex = vTex;
}
