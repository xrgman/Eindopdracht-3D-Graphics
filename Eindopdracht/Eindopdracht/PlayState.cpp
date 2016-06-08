#include "PlayState.h"
#include "GL\freeglut.h"
#include "Cube.h"
#include "Model.h"

float lastFrameTime = 0;
Cube cube = Cube();


//Model* bloem = new Model("models/bloemetje/PrimRoseP.obj");

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
	
}


void PlayState::Draw()
{
	glColor3f(0.1f, 1.0f, 0.2f);
	glBegin(GL_QUADS);
		glVertex3f(-15, -1, -15);
		glVertex3f(15, -1, -15);
		glVertex3f(15, -1, 15);
		glVertex3f(-15, -1, 15);
	glEnd();

	for (int x = -10; x <= 10; x += 5)
	{
		for (int y = -10; y <= 10; y += 5)
		{
			glPushMatrix();
			glTranslatef((float)x, 0.0f, (float)y);
			cube.Draw();
			glPopMatrix();
		}
	}
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
