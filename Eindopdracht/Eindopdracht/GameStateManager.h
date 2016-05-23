#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <vector>
#include "Camera.h"

class GameState;

class GameStateManager {
	public:
		void Init(Camera * camera);
		void Cleanup();

		void nextState();
		void previousState();

		void HandleEvents(bool keys[], bool specialKeys[]);
		void Update();
		void Draw();

		bool Running() { return m_running; }
		void Quit() { m_running = false; }

	private:
		// the stack of states
		std::vector<GameState*> states;
		Camera * camera;
		short currentState;
		bool m_running;
};
#endif
