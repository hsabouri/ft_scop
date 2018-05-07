#version 410

in vec4	color;
in vec2	tex;

out vec4	out_color;

uniform vec4	State;
uniform vec4	Start;
uniform vec4	End;
uniform sampler2D	Texture;

void main(void)
{
	vec4	tmp;
	vec4	tmp2;
	float z = gl_FragCoord.z / gl_FragCoord.w;

	tmp = mix(color * State.x, (Start + (End - Start) * (z * State.z)) * (1 - State.x), 1.0);
	tmp2 = texture(Texture, tex);
	out_color = mix(tmp, tmp2, 1.0);
}
