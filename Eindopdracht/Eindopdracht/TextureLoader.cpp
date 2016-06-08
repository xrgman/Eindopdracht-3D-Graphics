#include "TextureLoader.h"

void TextureLoader::loadTextures()
{
	textures.push_back(new Texture("textures/grass.jpg"));
	textures.push_back(new Texture("textures/highway.png"));
}

void TextureLoader::bindGrass()
{
	textures.at(0)->bind();
}

void TextureLoader::bindHighway()
{
	textures.at(1)->bind();
}
