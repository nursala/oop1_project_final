#pragma once

#include <SFML/Audio.hpp>
#include <Macros.h>


class SoundManager
{
public:
	SoundManager();
	void playSound(int sound);
	void pause(int sound);
	bool isPlaying(int sound) const;
private:
	sf::Sound m_sounds[4];
	sf::SoundBuffer m_soundBuffers[4];
	sf::Music m_backgroundMusic;
};