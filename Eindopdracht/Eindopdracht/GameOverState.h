#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include "Camera.h"

class GameOverState : public GameState {

	// Inherited via GameState
public:
	virtual void Init(GameStateManager * game, Camera * camera) override;
	virtual void Cleanup() override;
	virtual void HandleEvents(bool keys[], bool specialKeys[]) override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Idle() override;
	bool keys[255], specialKeys[255];

private:
	GameStateManager * gameManager;
	Camera * camera;
	int animationCounter;
	float red, green,blue;
	
};

#endif