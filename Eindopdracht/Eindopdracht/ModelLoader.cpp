#include "ModelLoader.h"

void ModdelLoader::loadModels()
{
	models.push_back(new Model("models/MainCar/police_car.obj")); //The car;
	models.push_back(new Model("models/streetlight/StreetLamp.obj")); //The streetLight;
	models.push_back(new Model("models/taxi/taxi.obj")); //The streetLight;
	models.push_back(new Model("models/Trees/lowpoyltree.obj"));
	models.push_back(new Model("models/Bush/bush1.obj"));

}
Model * ModdelLoader::getCar()
{
	return models.at(0);
}

Model * ModdelLoader::getLight()
{
	return models.at(1);
}

Model * ModdelLoader::getTaxi()
{
	return models.at(2);
}

Model * ModdelLoader::getTree1()
{
	return models.at(3);
}

Model * ModdelLoader::getBush()
{
	return models.at(4);
}
