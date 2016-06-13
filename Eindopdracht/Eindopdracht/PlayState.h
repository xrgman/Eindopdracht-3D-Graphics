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
		virtual void Idle() override;
		bool keys[255], specialKeys[255];
	private:
		GameStateManager * gameManager;
		Camera * camera;
		void loadModels();
		void moveCar(float angle, float frac);
		void backgroundMusicThread();
		void playSound(std::string filePath);
protected:
	
};

#endif

