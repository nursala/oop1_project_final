#include "GameObject/staticInclude/Gift/FreezeGuards.h"

FreezeGuards::FreezeGuards(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setInitPosition(position);
    setStandAble(true);
    setTextureForObject(AssetsManager::instance().getTexture(0));
}

//void FreezeGuards::FreezeAllGuards(Player robot)
//{
//	robot.addLife();
//}