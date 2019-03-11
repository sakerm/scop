#version 400

layout(location = 0) in vec3 position;

out vec3 elcolor;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(position, 1.0);
	elcolor = position;
}
