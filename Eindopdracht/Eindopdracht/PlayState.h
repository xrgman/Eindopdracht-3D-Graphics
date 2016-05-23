#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include "Camera.h"

class PlayState : public GameState {

	// Inherited via GameState
	public:
		virtual void Init(GameStateManager * game, Camera * camera) override;
		virtual void Cleanup() override;
		virtual void HandleEvents(bool keys[], bool specialKeys[]) override;
		virtual void Update() override;
		virtual void Draw() override;
	private:
		GameStateManager * gameManager;
		Camera * camera;
};

#endif

