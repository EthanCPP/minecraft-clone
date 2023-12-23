#include "CubeTexture.h"

CubeTexture::CubeTexture(
	const char* imageRight,
	const char* imageLeft,
	const char* imageTop,
	const char* imageBottom,
	const char* imageFront,
	const char* imageBack)
{
	glGenTextures(1, &cubemapTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// These are very important to prevent seams
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	this->attachImage(imageRight, 0);
	this->attachImage(imageLeft, 1);
	this->attachImage(imageTop, 2);
	this->attachImage(imageBottom, 3);
	this->attachImage(imageFront, 4);
	this->attachImage(imageBack, 5);
}

CubeTexture::~CubeTexture()
{

}

void CubeTexture::attachImage(const char* image, int iteration)
{
	int width, height, nChannels;
	unsigned char* data = stbi_load(image, &width, &height, &nChannels, 0);

	if (data)
	{
		stbi_set_flip_vertically_on_load(false);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + iteration,
			0,
			GL_RGB,
			width,
			height,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			data
		);
	}
	else
	{
		std::cout << "Failed to load texture " << image << std::endl;
	}

	stbi_image_free(data);
}

void CubeTexture::bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
}

void CubeTexture::unbind()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}