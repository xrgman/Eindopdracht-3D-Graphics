
#include "Sound.h"
#include "SFML/Audio.hpp"
#include <thread>

Sound::Sound()
{
}

void Sound::playMusic(std::string filePath)
{
	std::thread musicThread(&Sound::soundLoopThread,this, std::ref(filePath));
	musicThread.detach();
}

void Sound::playSound(std::string filePath)
{
	std::thread soundThread(&Sound::soundThread, this, std::ref(filePath));
	soundThread.detach();
}

void Sound::soundThread(std::string filePath)
{
	sf::SoundBuffer soundbuf;
	sf::Sound sound;
	soundbuf.loadFromFile(filePath.c_str());
	sound.setBuffer(soundbuf);
	sound.setLoop(false);
	sound.play();
	while (sound.getStatus() != sf::Sound::Status::Stopped);
}

void Sound::soundLoopThread(std::string filepath)
{
	sf::SoundBuffer soundbuf;
	sf::Sound sound;
	soundbuf.loadFromFile(filepath.c_str());
	sound.setBuffer(soundbuf);
	sound.setLoop(true);
	sound.play();
	while (sound.getStatus() != sf::Sound::Status::Stopped);
}
