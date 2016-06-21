#include <vector>
#include "PlayState.h"
#include "GL\freeglut.h"
#include "Cube.h"
#include "CubeWithTexture.h"
#include "Model.h"
#include "Entity.h"
#include "DrawUtil.h"
#include "Util.h"

void PlayState::Init(GameStateManager * game, Camera * camera)
{
	this->gameManager = game;
	this->camera = camera;
	camera->posX = -5.104399;
	camera->posY = 0.142510;
	camera->posZ = -2;
	camera->rotX = 18.30030;
	camera->rotY = -89.399963;
	score = 0;
	loadModels();
	sound = new Sound();
	sound->playMusic("music/background.wav");
}

void PlayState::loadModels()
{
	//Loading car:
	car = new Car(gameManager->getModelLoader()->getCar());
	entitys.push_back(car);
	Entity* enemyCar = new Entity(gameManager->getModelLoader()->getTaxi());
	enemyCar->rotation.y = 90;
	enemyCar->position.y = -1;
	enemyCar->position.x = -40;
	entitys.push_back(enemyCar);
	Entity* enemyCar2 = new Entity(gameManager->getModelLoader()->getTaxi());
	enemyCar2->rotation.y = 90;
	enemyCar2->position.y = -1;
	enemyCar2->position.x = -40;
	enemyCar2->position.z = -3.6;
	entitys.push_back(enemyCar2);
}

void PlayState::Cleanup()
{
	entitys.clear();
	car = NULL;
	score = 0;
	time = 0; 
	scrollWay = 0;
	sound->stop();
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
	//Updating scrolling map:
	scrollWay+=0.2;
	//Checking collision: 
	for (int x = 1; x < entitys.size(); x++) {
		entitys.at(x)->position.x = -29 + fmod(scrollWay,35)*1.5;
		if (!(car->dead) && car->hasCollision(entitys.at(x)->position)) {
			sound->playSound("music/crash.wav");
			car->dead = true;
		}
		//Respawning enemys:
		if (entitys.at(x)->position.x > 21) {
			score += 20 + rand() % 10;
			int side = rand() % 3;
			switch (side) {
				case 0:
					entitys.at(x)->position.z = 3.6;
					break;
				case 1:
					entitys.at(x)->position.z =	0;
					break;
				case 2:
					entitys.at(x)->position.z = -3.6;
					break;
			}
		}
	}
	//Dead animation:
	if (car->dead)
		car->position.x += 0.2;

	//Game over
	else if (car->gameOver == true) {
		gameManager->score = score;
		gameManager->time = time;
		gameManager->nextState();
	}

	//updating entitys:
	for (Entity* entity : entitys)
		entity->update(GLUT_ELAPSED_TIME);
}

void PlayState::Draw2D()
{
	//Setting right perspective: 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 1000, 0, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	
	//Drawing lives:
	int offset = 0;
	
	glEnable(GL_TEXTURE_2D);
		glColor4f(1.0f, 1.0f, 1.0f, 0);
		gameManager->getTextureLoader()->bindPoliceCar();
		for (int lives = 0; lives < car->getLives(); lives++) {
			square = SquareWithTexture(5+offset, 5, 0, 60, 100, 0, 1);
			square.Draw();
			offset += 65;
		}
	glDisable(GL_TEXTURE_2D);
	
	//Drawing score:
	DrawUtil::drawString("Score: "+ std::to_string(score), 10, 160);
	DrawUtil::drawString("Time: " + Util<float>::to_string_with_precision(time,5), 10, 140);
		
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void PlayState::Draw()
{
	glColor3f(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	for (float x = -40 + fmod(scrollWay,10); x <= 40 + fmod(scrollWay, 10); x += 10) {
		//Drawing highway:
		glDisable(GL_LIGHTING);
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
		//drawing streetLight:
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPushMatrix();
			glTranslatef(-5 + x, -0.9, 6);
			glScalef(0.3, 0.3, 0.3);
			glRotatef(90, 0, 1, 0);
			gameManager->getModelLoader()->getLight()->draw();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5 + x, -0.9, -6);
			glScalef(0.3, 0.3, 0.3);
			glRotatef(-90, 0, 1, 0);
			gameManager->getModelLoader()->getLight()->draw();
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
	}
	glDisable(GL_TEXTURE_2D);

	//Drawing models:
	for (Entity* entity : entitys)
		entity->Draw();

	//Drawing 2D stuff:
	glColor3f(255, 255, 255);
	Draw2D();
}

void PlayState::Idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	time += deltaTime;
	lastFrameTime = frameTime;
	const float speed = 6;
	if (specialKeys[GLUT_KEY_UP] || keys['w']);
		//camera->move(90, deltaTime*speed);
	if (specialKeys[GLUT_KEY_DOWN] || keys['s']);
		//camera->move(270, deltaTime*speed);
	if (specialKeys[GLUT_KEY_LEFT] || keys['a'])
		//camera->move(0, deltaTime*speed);
		car->moveCar(270, deltaTime*speed);
	if (specialKeys[GLUT_KEY_RIGHT] || keys['d'])
		//camera->move(180, deltaTime*speed);
		car->moveCar(180, deltaTime*speed);
}
