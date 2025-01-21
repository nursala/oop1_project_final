#include "GameObject/staticInclude/Bomb.h"

Bomb::Bomb(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setStandAble(true);
    setInitPosition(position);
    setTextureForObject(AssetsManager::instance().getTexture(0));
}

//void Bomb::update(float deltaTime)
//{
//	m_timeSinceSpawn += deltaTime;
//	if (m_timeSinceSpawn >= m_timeToExplode)
//	{
//		explode();
//	}
//}
//
//void Bomb::explode()
//{}
