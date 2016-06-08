#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <iostream>
#include "GL\freeglut.h"

class Texture {
	private:
		GLuint textureID;
		int width, height;
	public:
	
		Texture(const std::string &filName);
		void bind();
};
#endif
