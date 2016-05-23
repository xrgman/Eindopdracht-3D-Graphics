#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameStateManager.h"
#include "Camera.h"

class GameState {
	public:
		virtual void Init(GameStateManager* game, Camera * camera) = 0;
		virtual void Cleanup() = 0;
		virtual void HandleEvents(bool keys[], bool specialKeys[]) = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	protected: 
		GameState() { }
};
#endif
