#version 400

out vec4 color;

in vec2 texture_color;

flat in vec3 elcolor;

uniform int textureoupas;
uniform sampler2D text;

void main()
{
	if (textureoupas == 1)
		color = vec4(texture(text, texture_color).rgb, 1.0);
	else
		color = vec4(elcolor, 1.0);
}
