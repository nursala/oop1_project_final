#pragma once

#include <SFML/Graphics.hpp>
#include <Macros.h>



class TextureManager
{
public:
	TextureManager();
	sf::Texture* getTexture(int id);

private:
	sf::Texture m_textures[NUM_OF_TEXTURES];
};