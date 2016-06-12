#ifndef ENTITY_H
#define ENTITY_H

#include "Vec3f.h"
#include "Model.h"

class Entity {
	public:
		Entity(Model* model);
		~Entity();
		virtual void draw();
		virtual void update(float elapsedTime) {};
		Vec3f position;
		Vec3f rotation;
		float scale;
		bool dead;

		bool hasCollision(const Vec3f &position);
	protected:
		Model* model;
};
#endif
