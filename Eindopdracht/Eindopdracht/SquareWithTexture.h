#ifndef SQUAREWITHTEXTURE_H
#define SQUAREWITHTEXTURE_H

#include <vector>
#include "Figure.h"

class SquareWithTexture : public Figure {
public:
	virtual void Draw() override;
	SquareWithTexture(float, float, float, float, float, float, int);
	SquareWithTexture();
	~SquareWithTexture();
private:
	virtual void Intialize() override;
	float x, y, z, width, height, depth, textureOffset;
};
#endif