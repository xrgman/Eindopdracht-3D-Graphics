#include "PlayState.h"
#include "GL\freeglut.h"

float lastFrameTime = 0;

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
}

void PlayState::Idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;
	const float speed = 3;
	if (specialKeys[GLUT_KEY_UP])
		camera->move(90, deltaTime*speed);
	if (specialKeys[GLUT_KEY_DOWN])
		camera->move(270, deltaTime*speed);
	if (specialKeys[GLUT_KEY_LEFT])
		camera->move(0, deltaTime*speed);
	if (specialKeys[GLUT_KEY_RIGHT])
		camera->move(180, deltaTime*speed);

}
