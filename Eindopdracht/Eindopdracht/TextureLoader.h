#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <vector>
#include "Texture.h"

class TextureLoader {
	public:
		void loadTextures();
		void bindGrass();
		void bindHighway();
		void bindSideway();
		void bindHeart();
		void bindSky();
		void bindGameOver();
	private:
		std::vector<Texture*> textures;
};
#endif
