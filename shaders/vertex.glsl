#version 400

layout(location = 0) in vec3 position;

flat out vec3 elcolor;

out vec2 texture_color;

uniform mat4 mvp;

vec2 cylinder_mapping() {
		return (vec2(atan(position.z, position.x) / 3.14 * 0.5 + 0.5, position.y / 10.0) * 3);
}

void main()
{
	float gris;
	float intensity;

	gris = (position.x + position.y + position.z) / 3.0;
	if (gris < 0.35)
		gris += 0.85;
	if (gris > 0.65)
		gris -= 0.50;
	gl_Position = mvp * vec4(position, 1.0);
	elcolor = vec3(gris, gris, gris);
	texture_color = cylinder_mapping();
}
