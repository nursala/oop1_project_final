#pragma once

#include <SFML/Graphics.hpp>
#include "Assets/TextureManger.h"
#include "Assets/SoundManger.h"
#include "Assets/LevelManger.h"


class AssetsManager
{
public:
	~AssetsManager();

	static AssetsManager& instance(); // Singleton instance
	sf::Texture* getTexture(int wanted);
	const std::vector<std::string> getMap()
	{
		return m_levelManger.getLevelData(); // Use reference to avoid copying
	}

	void playSound(int sound);
	sf::Font* getFont();
	void pause(int sound);
	bool isPlaying(int sound);
	int getLevelCount() const;
	void loadNextLevel();
	int getTime() const;

	int getRow() const;
	int getColumn() const;

	int getLevel() const;

private:
	AssetsManager(); // Private constructor to prevent direct instantiatio

	LevelManger m_levelManger;
	TextureManager m_textureManager;
	SoundManager m_soundManager;
	sf::Font m_font;
};
