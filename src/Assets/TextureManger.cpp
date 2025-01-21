#include "Assets/TextureManger.h"
#include <iostream>

TextureManager::TextureManager()
{
	int i = 0;
	for (const auto& [key, value] : TexturePath) {
 		m_textures[i].loadFromFile(value);
		i++;
	}
}

sf::Texture* TextureManager::getTexture(int id)
{
	return &m_textures[id];
}