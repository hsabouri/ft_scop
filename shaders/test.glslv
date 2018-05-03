#version 410

attribute vec4 	vPos;
attribute vec4 	vCol;
varying vec4	color;

void main(void)
{
	gl_Position = vPos;
	color = vCol;
}
