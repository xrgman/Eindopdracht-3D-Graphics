#include "Entity.h"
#include <GL/freeglut.h>

Entity::Entity(Model* model)
{
	this->model = model;
	scale = 1;
	dead = false;
	draw = true;
}

Entity::~Entity()
{
}

void Entity::Draw()
{
	if (draw) {
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation.x, 1, 0, 0);
		glRotatef(rotation.y, 0, 1, 0);
		glRotatef(rotation.z, 0, 0, 1);
		glScalef(scale, scale, scale);
		model->draw();
		glPopMatrix();
	}
}

bool Entity::hasCollision(const Vec3f & point)
{
	Vec3f center = position + model->center;
	float distance = ((point.x - center.x) * (point.x - center.x) + (point.z - center.z)*(point.z - center.z));
	if (distance < model->radius*scale*model->radius*scale) {
		return true;
	}
	else {
		return false;
	}
	return false;
}


