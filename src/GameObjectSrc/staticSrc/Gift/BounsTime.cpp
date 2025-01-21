#include "GameObject/staticInclude/Gift/BounsTime.h"

BounsTime::BounsTime(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setStandAble(true);
    setInitPosition(position);
    setTextureForObject(AssetsManager::instance().getTexture(0));
}