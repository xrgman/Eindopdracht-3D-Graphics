#include "TextureLoader.h"

void TextureLoader::loadTextures()
{
	textures.push_back(new Texture("textures/Grass.jpg"));
	textures.push_back(new Texture("textures/highway.jpg"));
	textures.push_back(new Texture("textures/Sideway.jpg"));
	textures.push_back(new Texture("textures/heart.png"));
	textures.push_back(new Texture("textures/sky.jpg"));
	textures.push_back(new Texture("textures/GameOver.png"));
}

void TextureLoader::bindGrass()
{
	textures.at(0)->bind();
}

void TextureLoader::bindHighway()
{
	textures.at(1)->bind();
}

void TextureLoader::bindSideway()
{
	textures.at(2)->bind();
}

void TextureLoader::bindHeart()
{
	textures.at(3)->bind();
}

void TextureLoader::bindSky()
{
	textures.at(4)->bind();
}

void TextureLoader::bindGameOver()
{
	textures.at(5)->bind();
}
