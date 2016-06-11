#ifndef CUBEWITHTEXTURE_H
#define CUBEWITHTEXTURE_H

#include <vector>
#include "Figure.h"

class CubeWithTexture : public Figure {
	public:
		virtual void Draw() override;
		CubeWithTexture();
		~CubeWithTexture();
	private:
		virtual void Intialize() override;
};
#endif
