#define _USE_MATH_DEFINES
#include <math.h>
#include "Car.h"

Car::Car(Model * model) : Entity(model)
{
	this->position.y = -1;
	this->rotation.y = -90;
	this->scale = 0.5;
	this->lives = 3;
	this->deadAnimation = false;
}

void Car::moveCar(float angle, float frac)
{
	if ((angle == 270 && position.z < 3.8) || (angle == 180 && position.z > -3.8))
		position.z += (float)cos((45 + angle) / 180 * M_PI) * frac;
}

int Car::getLives()
{
	return lives;
}

void Car::update(float elapsedTime)
{
	//Dead animation:
	if (dead && lives > 1)
		deadAnimation++;
	else if (dead && lives > 0) {
		lives--;
		gameOver = true;
	}
	if (deadAnimation == 120) {
		position.x = 0;
		position.z = 0;
		lives--;
		deadAnimation++;
		dead = false;
	}
	else if (deadAnimation >= 120 && deadAnimation < 180) {
		deadAnimation++;
		if (deadAnimation % 20 > 10)
			draw = false;
		else
			draw = true;
	}
	else if(deadAnimation >= 180) {
		dead = false;
		deadAnimation = 0;
	}	
}



