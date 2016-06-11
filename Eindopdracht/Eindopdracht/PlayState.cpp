#include <math.h>
#include "PlayState.h"
#include "GL\freeglut.h"
#include "Cube.h"
#include "CubeWithTexture.h"
#include "SquareWithTexture.h"
#include "Model.h"

float lastFrameTime = 0;
Cube cube = Cube();
CubeWithTexture cube2 = CubeWithTexture();
SquareWithTexture square;
float scrollWay = 0;

void PlayState::Init(GameStateManager * game, Camera * camera)
{
	this->gameManager = game;
	this->camera = camera;
	
}

void PlayState::Cleanup()
{
}

void PlayState::HandleEvents(bool keys[], bool specialKeys[])
{
	for (int x = 0; x < 255; x++) {
		this->keys[x] = keys[x];
		this->specialKeys[x] = specialKeys[x];
	}
}

void PlayState::Update()
{
	//scrollWay-=0.2;
}


void PlayState::Draw()
{
	glColor3f(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	for (float x = -40 + fmod(scrollWay,10); x <= 40 + fmod(scrollWay, 10); x += 10) {
		//Drawing highway:
		gameManager->getTextureLoader()->bindHighway();
		square = SquareWithTexture(-5 + x, -1, -5, 10, 0, 10,2);
		square.Draw();
		//drawing sideOfway:
		gameManager->getTextureLoader()->bindGround2();
		//Top - right:
		square = SquareWithTexture(-5 + x, -0.9, 5, 10, 0, 1,1);
		square.Draw();
		//Side:
		square = SquareWithTexture(-5 + x, -0.9, 5, 10, -0.1, 0,1);
		square.Draw();
		//Top - left:
		square = SquareWithTexture(-5 + x, -0.9, -6, 10, 0, 1, 1);
		square.Draw();
		//Side:
		square = SquareWithTexture(-5 + x, -0.9, -5, 10, -0.1, 0, 1);
		square.Draw();
		//Drawing grass: 
		gameManager->getTextureLoader()->bindGrass();
		square = SquareWithTexture(-5 + x, -0.92, -6, 10, 0, -10, 8);
		square.Draw();
		square = SquareWithTexture(-5 + x, -0.92, 6, 10, 0, 10, 8);
		square.Draw();

	}
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
		glTranslatef(40 + fmod(scrollWay, 90), 0.0f, (float)2);
		gameManager->getModelLoader()->getPlant()->draw();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	gameManager->getTextureLoader()->bindGround2();
	cube2.Draw();
	glDisable(GL_TEXTURE_2D);

	//Light fix:
	glPushMatrix();
		glTranslatef(200, 200, 200);
		cube.Draw();
	glPopMatrix();
	glColor3f(255, 255, 255);
}

void PlayState::Idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;
	const float speed = 3;
	if (specialKeys[GLUT_KEY_UP] || keys['w'])
		camera->move(90, deltaTime*speed);
	if (specialKeys[GLUT_KEY_DOWN] || keys['s'])
		camera->move(270, deltaTime*speed);
	if (specialKeys[GLUT_KEY_LEFT] || keys['a'])
		camera->move(0, deltaTime*speed);
	if (specialKeys[GLUT_KEY_RIGHT] || keys['d'])
		camera->move(180, deltaTime*speed);
}
