#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <vector>
#include "Model.h"

class ModdelLoader {
	public:
		void loadModels();
		Model* getPlant();
		Model* getCar();
		Model* getLight();
		Model *getTaxi();
		Model *getHeart();
	private:
		std::vector<Model*> models;
};
#endif
