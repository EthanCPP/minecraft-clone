#pragma once
#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.h"

class CubeTexture
{
public:
	CubeTexture(
		const char* imageRight,
		const char* imageLeft,
		const char* imageTop,
		const char* imageBottom,
		const char* imageFront,
		const char* imageBack);
	~CubeTexture();

	void bind();
	void unbind();

private:
	GLuint ID;
	GLenum type;

	unsigned int cubemapTexture;

	void attachImage(const char* image, int iteration);
};
