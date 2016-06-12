#ifndef CUBEWITHTEXTURE_H
#define CUBEWITHTEXTURE_H

#include <vector>
#include "Figure.h"
#include "Vec3f.h"

class CubeWithTexture : public Figure {
	public:
		virtual void Draw() override;
		CubeWithTexture();
		~CubeWithTexture();
		Vec3f position;
		Vec3f rotation;
		float scale;
	private:
		virtual void Intialize() override;
};
#endif
