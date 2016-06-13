#include "ModelLoader.h"

void ModdelLoader::loadModels()
{
	models.push_back(new Model("models/bloemetje/PrimRoseP.obj")); //test plant;
	models.push_back(new Model("models/porsche/police_car.obj")); //The car;
	models.push_back(new Model("models/taxi/taxi.obj")); //The streetLight;
}

Model * ModdelLoader::getPlant()
{
	return models.at(0);
}

Model * ModdelLoader::getCar()
{
	return models.at(1);
}

Model * ModdelLoader::getLight()
{
	return models.at(3);
}

Model * ModdelLoader::getTaxi()
{
	return models.at(2);
}
