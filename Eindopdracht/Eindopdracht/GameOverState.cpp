#include "GameOverState.h"
#include "DrawUtil.h"
#include "SquareWithTexture.h"
#include "Util.h"

void GameOverState::Init(GameStateManager * game, Camera * camera)
{
	this->gameManager = game;
	this->camera = camera;
	animationCounter++;
	red = 1.0f;
	green = 0.0f;
	blue = 0.0f;
}

void GameOverState::Cleanup()
{
}

void GameOverState::HandleEvents(bool keys[], bool specialKeys[])
{
	for (int x = 0; x < 255; x++) {
		this->keys[x] = keys[x];
		this->specialKeys[x] = specialKeys[x];
	}
}

void GameOverState::Update()
{
	if (animationCounter <= 255) {
		red = 1.0 - (float)1 / 255 * (float)animationCounter;
		green = 0 + (float)1 / 255 * (float)animationCounter;
	}
	else if (animationCounter <= 510) {
		green = 1.0 - (float)1 / 255 * (float)(animationCounter-255);
		blue = 0 + (float)1 / 255 * (float)(animationCounter-255);
	}
	else if (animationCounter <= 765) {
		blue = 1.0 - (float)1 / 255 * (float)(animationCounter - 510);
		red = 0 + (float)1 / 255 * (float)(animationCounter - 510);
	}
	else
		animationCounter = 0;
	animationCounter++;
	
}

void GameOverState::Draw()
{
	//Setting right perspective: 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 1000, 0, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	
	glEnable(GL_TEXTURE_2D);
	glColor3f(red, green, blue);
	gameManager->getTextureLoader()->bindGameOver();
	SquareWithTexture square = SquareWithTexture(0, 0, 0, 1000, gameManager->height, 0, 1);
	square.Draw();

	

	glDisable(GL_TEXTURE_2D);

	//Drawing score:
	DrawUtil::drawString("Score: " + std::to_string(gameManager->score) + " Points", 450, gameManager->height - 400);
	DrawUtil::drawString("Time: " + Util<float>::to_string_with_precision(gameManager->time,5) + " Seconds", 450, gameManager->height - 380);
	DrawUtil::drawString("Press X to exit or R to restart", 420, gameManager->height - 100);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void GameOverState::Idle()
{
	if (keys['x'] || keys['X']) //Exit
		exit(0);
	else if (keys['r'] || keys['R'])
		gameManager->previousState();
}
