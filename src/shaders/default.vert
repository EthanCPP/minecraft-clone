#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

uniform mat4 model;
uniform mat4 camMatrix;
uniform float scale;

out vec3 color;
out vec3 tex;
out vec3 normal;
out vec3 modelPos;

void main()
{
	modelPos = vec3(model * vec4(aPos, 1.0f)) * scale;
	gl_Position = camMatrix * vec4(modelPos, 1.0f);

	// send color to frag shader
	color = aColor;

	// send texture coords to frag shader
	tex = vec3(aPos.x, aPos.y, aPos.z);

	// send normals to frag shader
	normal = aNormal;
}