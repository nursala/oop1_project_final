#include "Assets/AssetsManger.h"

// Singleton implementation
AssetsManager& AssetsManager::instance()
{
    static AssetsManager instance; // Static local instance (Lazy Initialization)
    return instance;
}

// Private Constructor
AssetsManager::AssetsManager() {}

// Destructor (optional, but ensures no accidental deletion)
AssetsManager::~AssetsManager() {}

// Example function to get a texture (modify as needed)

sf::Texture* AssetsManager::getTexture(int wanted)
{
    return m_textureManager.getTexture(wanted); // Assumes `getTexture(int)` exists in TextureManager
}

void AssetsManager::loadNextLevel()
{
	m_levelManger.prepareNewLevel(); // Assumes `prepareNewLevel` exists in LevelManger
}

int AssetsManager::getTime() const
{
	return m_levelManger.getTime(); // Assumes `getTime
}

int AssetsManager::getRow() const
{
    return m_levelManger.getRow(); // Assumes `getRow` exists in LevelManger
}

int AssetsManager::getColumn() const
{
    return m_levelManger.getColumn(); // Assumes `getCol` exists in LevelManger
}

int AssetsManager::getLevel() const
{
	return m_levelManger.getLevel(); // Assumes `getLevel` exists in LevelManger
}

void AssetsManager::playSound(int sound)
{
	m_soundManager.playSound(sound);
}

sf::Font* AssetsManager::getFont()
{
    m_font.loadFromFile("C:/Windows/Fonts/times.ttf");
	return &m_font;
}

void AssetsManager::pause(int sound)
{
	m_soundManager.pause(sound);
}

bool AssetsManager::isPlaying(int sound)
{
	if (m_soundManager.isPlaying(sound))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int AssetsManager::getLevelCount() const
{
	return m_levelManger.getLevelCount();
}