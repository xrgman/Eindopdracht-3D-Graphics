#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <vector>
#include "Texture.h"

class TextureLoader {
	public:
		void loadTextures();
		void bindGrass();
		void bindHighway();
		void bindGround1();
		void bindGround2();
		void bindPoliceCar();
	private:
		std::vector<Texture*> textures;
};
#endif
