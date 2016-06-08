#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <vector>
#include "Texture.h"

class TextureLoader {
	public:
		void loadTextures();
		void bindGrass();
		void bindHighway();
	private:
		std::vector<Texture*> textures;
};
#endif
