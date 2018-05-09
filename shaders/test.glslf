#version 410

in vec4	color;
in vec2	tex;

uniform vec4	State;
uniform vec4	Start;
uniform vec4	End;
uniform sampler2D	Texture;

void main(void)
{
	vec4	tmp;
	vec4	tmp2;
	float z = gl_FragCoord.z / gl_FragCoord.w;

	tmp = mix(color * State.x, (Start + (End - Start) * (z * State.z)) * (1 - State.x), State.y);
	tmp2 = texture(Texture, tex);
	gl_FragColor = mix(tmp, tmp2, State.z);
}
