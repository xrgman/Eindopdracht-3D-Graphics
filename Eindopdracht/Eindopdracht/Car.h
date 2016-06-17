#ifndef CAR_H
#define CAR_H

#include "Entity.h"
#include "Model.h"

class Car : public Entity {
	public:
		Car(Model* model);
		void moveCar(float angle, float frac);
		int getLives();
		virtual void update(float elapsedTime) override;
		bool gameOver;
	private:
		int lives;
		int deadAnimation;
};

#endif
