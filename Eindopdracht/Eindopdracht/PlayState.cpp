#include <vector>
#include "PlayState.h"
#include "GL\freeglut.h"
#include "Cube.h"
#include "CubeWithTexture.h"
#include "Model.h"
#include "Entity.h"

Cube cube = Cube();
std::vector<Entity *> entitys;

void PlayState::Init(GameStateManager * game, Camera * camera)
{
	this->gameManager = game;
	this->camera = camera;
	camera->posX = -5.104399;
	camera->posY = 0.142510;
	camera->posZ -= 2;
	camera->rotX = 18.30030;
	camera->rotY = -89.399963;
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
		if (entitys.at(0)->hasCollision(entitys.at(x)->position) && !entitys.at(0)->dead) {
			sound->playSound("music/crash.wav");
			entitys.at(0)->dead = true;
		}
		//Respawning enemys:
		if (entitys.at(x)->position.x > 10) {
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

	//updating entitys:
	for (Entity* entity : entitys)
		entity->update(GLUT_ELAPSED_TIME);

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
		//drawing streetLight:
		//glPushMatrix();
		//	glTranslatef(-5 + x, -0.9, 5);
		//	//gameManager->getModelLoader()->getLight()->draw();
		//glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);

	//Drawing models:
	for (Entity* entity : entitys)
		entity->Draw();

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
	const float speed = 5;
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
