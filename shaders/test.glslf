#version 410

in vec4	color;
in vec2	tex;

uniform vec4	State;
uniform vec4	Start;
uniform vec4	End;
uniform sampler2D	Texture;

out vec4	out_color;

void main(void)
{
	vec4	tmp;
	vec4	tmp2;
	float z = (gl_FragCoord.z / gl_FragCoord.w) / 3;

	tmp = mix(color, Start + (End - Start) * z, State.y);
	tmp2 = texture(Texture, tex);
	out_color = mix(tmp, tmp2, State.z);
}
