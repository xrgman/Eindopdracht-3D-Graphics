#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <vector>
#include "Model.h"

class ModdelLoader {
	public:
		void loadModels();
		Model* getPlant();
	private:
		std::vector<Model*> models;
};
#endif
