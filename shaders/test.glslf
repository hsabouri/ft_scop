#version 410

varying vec4	color;
varying vec2	tex;

uniform vec4	State;
uniform vec4	Start;
uniform vec4	End;
uniform sampler2D	Texture;

void main(void)
{
	float z = gl_FragCoord.z / gl_FragCoord.w;
	gl_FragColor = (color * State.x +\
				   (Start + (End - Start) * (z * State.z)) * (1 - State.x)) * State.y +\
				   texture(Texture, tex) * (1 - State.y);
}
