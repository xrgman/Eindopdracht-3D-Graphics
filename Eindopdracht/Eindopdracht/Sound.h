#ifndef SOUND_H
#define SOUND_H

#include <string>

class Sound {
	public:
		Sound();
		void playMusic(std::string filePath);
		void playSound(std::string filePath);
	private:
		void soundThread(std::string filePath);
		void soundLoopThread(std::string filepath);
};
#endif
