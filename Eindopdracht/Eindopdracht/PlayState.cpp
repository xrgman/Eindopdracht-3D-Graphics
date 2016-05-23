#include "PlayState.h"
#include "GL\freeglut.h"

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
	if (specialKeys[GLUT_KEY_UP])
		camera->posY+=5;
}

void PlayState::Update()
{
}

void PlayState::Draw()
{
}
