#include "GameStateManager.h"
#include "GameState.h"
#include "PlayState.h"


void GameStateManager::Init(Camera * camera)
{
	this->camera = camera;
	Cleanup();
	//Adding moddelloader;
	moddelLoader = new ModdelLoader();
	//Adding textureLoader:
	textureLoader = new TextureLoader();
	//Adding states:
	states.push_back(new PlayState());
	states.at(currentState)->Init(this,camera);
}

void GameStateManager::Cleanup()
{
	this->states.clear();
	currentState = 0;
}

void GameStateManager::nextState()
{
	if (currentState < states.size() -1) {
		currentState++;
		states.at(currentState)->Init(this,camera);
	}
}

void GameStateManager::previousState()
{
	if (currentState > 0) {
		currentState--;
		states.at(currentState)->Init(this,camera);
	}
}

void GameStateManager::HandleEvents(bool keys[], bool specialKeys[])
{
	if(!states.empty())
		states.at(currentState)->HandleEvents(keys,specialKeys);
}

void GameStateManager::Update()
{
	if (!states.empty())
		states.at(currentState)->Update();
}

void GameStateManager::Draw()
{
	if (!states.empty())
		states.at(currentState)->Draw();
}

void GameStateManager::Idle()
{
	if (!states.empty())
		states.at(currentState)->Idle();
}

ModdelLoader * GameStateManager::getModelLoader()
{
	return moddelLoader;
}

TextureLoader * GameStateManager::getTextureLoader()
{
	return textureLoader;
}

