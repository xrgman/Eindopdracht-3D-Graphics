#include "ModelLoader.h"

void ModdelLoader::loadModels()
{
	models.push_back(new Model("models/bloemetje/PrimRoseP.obj")); //test plant;
}

Model * ModdelLoader::getPlant()
{
	return models.at(0);
}
