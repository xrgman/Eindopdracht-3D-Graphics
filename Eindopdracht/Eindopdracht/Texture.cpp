#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string & fileName)
{
	int bpp;
	stbi_set_flip_vertically_on_load(true);
	char* imgData = (char*)stbi_load(fileName.c_str(), &width, &height, &bpp, 4);

	if (!imgData)
		std::cout << stbi_failure_reason() << std::endl;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	stbi_image_free(imgData);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}