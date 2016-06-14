#include "DrawUtil.h"
#include <GL\freeglut.h>

void DrawUtil::drawString(std::string string, int x, int y)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < string.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}
