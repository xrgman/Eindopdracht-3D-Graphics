#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <vector>
#include "Camera.h"
#include "ModelLoader.h"
#include "TextureLoader.h"

class GameState;

class GameStateManager {
	public:
		void Init(Camera * camera);
		void Start();
		void Cleanup();

		void nextState();
		void previousState();

		void HandleEvents(bool keys[], bool specialKeys[]);
		void Update();
		void Draw();
		void Idle();

		ModdelLoader* getModelLoader();
		TextureLoader* getTextureLoader();

		bool Running() { return m_running; }
		void Quit() { m_running = false; }

		//Game things:
		long long int score;
		float time;
		int width, height;

	private:
		// the stack of states
		std::vector<GameState*> states;
		Camera * camera;
		ModdelLoader *moddelLoader;
		TextureLoader *textureLoader;
		short currentState;
		bool m_running;
		
};
#endif
