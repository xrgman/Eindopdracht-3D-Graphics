#include "TextureLoader.h"

void TextureLoader::loadTextures()
{
	textures.push_back(new Texture("textures/grass.jpg"));
	textures.push_back(new Texture("textures/highway2.jpg"));
	textures.push_back(new Texture("textures/ground1.jpg"));
	textures.push_back(new Texture("textures/ground2.jpg"));
	textures.push_back(new Texture("textures/heart.png"));
	//textures.push_back(new Texture("textures/policeCar.png"));
}

void TextureLoader::bindGrass()
{
	textures.at(0)->bind();
}

void TextureLoader::bindHighway()
{
	textures.at(1)->bind();
}

void TextureLoader::bindGround1()
{
	textures.at(2)->bind();
}

void TextureLoader::bindGround2()
{
	textures.at(3)->bind();
}

void TextureLoader::bindPoliceCar()
{
	textures.at(4)->bind();
}
