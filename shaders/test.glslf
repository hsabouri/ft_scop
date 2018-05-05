#version 410

varying vec4	color;

uniform vec4	State;
uniform vec4	Start;
uniform vec4	End;

void main(void)
{
	float z = gl_FragCoord.z / gl_FragCoord.w;
	gl_FragColor = color * State.x + (Start + (End - Start) * z) * (1 - State.x);
}
