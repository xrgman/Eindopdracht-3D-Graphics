#ifndef SOUND_H
#define SOUND_H

#include <string>
#include "SFML/Audio.hpp"

class Sound {
	public:
		Sound();
		void playMusic(std::string filePath);
		void playSound(std::string filePath);
		void stop();
	private:
		void soundThread(std::string filePath);
		void soundLoopThread(std::string filepath);
		sf::Sound globalSound;
};
#endif
