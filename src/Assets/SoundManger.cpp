#include "Assets/SoundManger.h"
#include <iostream>

using std::cout;
using std::endl;

SoundManager::SoundManager() {

	int i = 0;
	for (const auto& [key, value] : SOUND_FILE) {
		if (!m_soundBuffers[i].loadFromFile(value)) {
			std::cerr << "Error loading sound file: " << std::endl;
			continue;
		}
		else
		{
			std::cout << value << std::endl;
		}
		m_sounds[i].setBuffer(m_soundBuffers[i]);
		i++;
	}
	//playSound(RUNNING_TIME);???
}

void SoundManager::playSound(int sound)
{
	m_sounds[sound].setVolume(100);
	m_sounds[sound].play();
}

void SoundManager::pause(int sound)
{
	m_sounds[sound].pause();
}

bool SoundManager::isPlaying(int sound) const
{
	return m_sounds[sound].getStatus() == sf::Sound::Playing;
}

