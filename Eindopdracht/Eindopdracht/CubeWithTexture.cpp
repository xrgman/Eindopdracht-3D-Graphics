#include "CubeWithTexture.h"
#include "GL\freeglut.h"

CubeWithTexture::CubeWithTexture()
{
	Intialize();
}

CubeWithTexture::~CubeWithTexture()
{
	vertices.clear();
}

void CubeWithTexture::Intialize()
{
	//Back:
	vertices.push_back(Vertex{ -1, -1, -1,		0,0,1,		0,0 });
	vertices.push_back(Vertex{ -1,  1, -1,		0,0,1,		0,1 });
	vertices.push_back(Vertex{ 1,  1, -1,		0,0,1,		1,1 });
	vertices.push_back(Vertex{ 1, -1, -1,		0,0,1,		0,1 });
	//Front:
	vertices.push_back(Vertex{ -1, -1,  1,		0,0,-1,		0,0 });
	vertices.push_back(Vertex{ -1,  1,  1,		0,0,-1,		0,1 });
	vertices.push_back(Vertex{ 1,  1,  1,		0,0,-1,		1,1 });
	vertices.push_back(Vertex{ 1, -1,  1,		0,0,-1,		1,0 });
	//Bottom:?
	vertices.push_back(Vertex{ -1,  -1, -1,		0,-1,0,		0,0 });
	vertices.push_back(Vertex{ -1,  -1,  1,		0,-1,0,		0,1 });
	vertices.push_back(Vertex{ 1,  -1,  1,		0,-1,0,		1,1 });
	vertices.push_back(Vertex{ 1,  -1, -1,		0,-1,0,		1,0 });
	//Top:
	vertices.push_back(Vertex{ -1,  1, -1,		0,1,0,		0,0 });
	vertices.push_back(Vertex{ -1,  1,  1,		0,1,0,		0,1 });
	vertices.push_back(Vertex{ 1,  1,  1,		0,1,0,		1,1 });
	vertices.push_back(Vertex{ 1,  1, -1,		0,1,0,		1,0 });
	//Left:
	vertices.push_back(Vertex{ -1, -1, -1,		-1,0,0,		0,0 });
	vertices.push_back(Vertex{ -1, -1,  1,		-1,0,0,		0,1 });
	vertices.push_back(Vertex{ -1,  1,  1,		-1,0,0,		1,1 });
	vertices.push_back(Vertex{ -1,  1, -1,		-1,0,0,		1,0 });
	//Right:
	vertices.push_back(Vertex{ 1, -1, -1,		1,0,0,		0,0 });
	vertices.push_back(Vertex{ 1, -1,  1,		1,0,0,		1,0 });
	vertices.push_back(Vertex{ 1,  1,  1,		1,0,0,		1,1 });
	vertices.push_back(Vertex{ 1,  1, -1,		1,0,0,		0,1 });
}

void CubeWithTexture::Draw()
{
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), ((float*)vertices.data()) + 0);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), ((float*)vertices.data()) + 3);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), ((float*)vertices.data()) + 6);
	glDrawArrays(GL_QUADS, 0, vertices.size());

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}
