#include "Cube.h"
#include "GL\freeglut.h"

Cube::Cube()
{
	Intialize();
}

Cube::~Cube()
{
	vertices.clear();
}

void Cube::Draw()
{
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), ((float*)vertices.data()) + 0);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), ((float*)vertices.data()) + 3);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), ((float*)vertices.data()) + 6);
	glDrawArrays(GL_QUADS, 0, vertices.size());

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

void Cube::Intialize()
{
	//Back:
	vertices.push_back(Vertex{ -1, -1, -1, 0,0,1, 0.3f,1,1,1 });
	vertices.push_back(Vertex{ -1,  1, -1, 0,0,1, 0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1,  1, -1, 0,0,1, 0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1, -1, -1, 0,0,1, 0.3f,1,1,1 });
	//Front:
	vertices.push_back(Vertex{ -1, -1,  1, 0,0,-1, 0.3f,1,1,1 });
	vertices.push_back(Vertex{ -1,  1,  1, 0,0,-1, 0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1,  1,  1, 0,0,-1, 0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1, -1,  1, 0,0,-1, 0.3f,1,1,1 });
	//Bottom:?
	vertices.push_back(Vertex{ -1,  -1, -1,		0,-1,0,		1,1,0.3f,1 });
	vertices.push_back(Vertex{ -1,  -1,  1,		0,-1,0,		1,1,0.3f,1 });
	vertices.push_back(Vertex{ 1,  -1,  1,		0,-1,0,		1,1,0.3f,1 });
	vertices.push_back(Vertex{ 1,  -1, -1,		0,-1,0,		1,1,0.3f,1 });
	//Top:
	vertices.push_back(Vertex{ -1,  1, -1,		0,1,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ -1,  1,  1,		0,1,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1,  1,  1,		0,1,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1,  1, -1,		0,1,0,		0.3f,1,1,1 });
	//Left:
	vertices.push_back(Vertex{ -1, -1, -1,		-1,0,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ -1, -1,  1,		-1,0,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ -1,  1,  1,		-1,0,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ -1,  1, -1,		-1,0,0,		0.3f,1,1,1 });
	//Right:
	vertices.push_back(Vertex{ 1, -1, -1,		1,0,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1, -1,  1,		1,0,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1,  1,  1,		1,0,0,		0.3f,1,1,1 });
	vertices.push_back(Vertex{ 1,  1, -1,		1,0,0,		0.3f,1,1,1 });
}

