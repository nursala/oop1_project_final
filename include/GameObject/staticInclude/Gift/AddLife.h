#pragma once

#include "GameObject/staticInclude/Gift.h"

class AddLife : public Gift
{
public:
	AddLife(sf::Vector2f position, sf::Vector2f size);
private:
	int m_lifeToAdd = 1;
};