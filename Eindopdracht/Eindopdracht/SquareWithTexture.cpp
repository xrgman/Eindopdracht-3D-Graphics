#include "SquareWithTexture.h"
#include "GL\freeglut.h"

SquareWithTexture::SquareWithTexture(float x, float y, float z, float depth, float height, float width, int textureOffset)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->textureOffset = textureOffset;
}

SquareWithTexture::SquareWithTexture()
{
}

SquareWithTexture::~SquareWithTexture()
{
	vertices.clear();
}

void SquareWithTexture::Intialize()
{
}


void SquareWithTexture::Draw()
{
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);							glVertex3f(x, 		y,			z);
		glTexCoord2f(0, textureOffset);				glVertex3f(x+depth, y,			z);
		glTexCoord2f(textureOffset, textureOffset); glVertex3f(x+depth, y+height,	z+width);
		glTexCoord2f(textureOffset, 0);				glVertex3f(x,		y+height,	z+width);
	glEnd();
}