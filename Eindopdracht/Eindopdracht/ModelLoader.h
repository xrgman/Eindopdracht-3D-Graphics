#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <vector>
#include "Model.h"

class ModdelLoader {
	public:
		void loadModels();
		Model* getCar();
		Model* getLight();
		Model *getTaxi();
		Model *getTree1();
		Model *getBush();
	private:
		std::vector<Model*> models;
};
#endif
