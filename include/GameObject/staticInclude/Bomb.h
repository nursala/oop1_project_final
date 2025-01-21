#pragma once
#include "GameObject/StaticObject.h"


class Bomb : public StaticObject
{
public:
	Bomb(sf::Vector2f position, sf::Vector2f size);
	
private:
	float m_timeToExplode = 4.0f;
};
