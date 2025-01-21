#include "GameObject/staticInclude/Gift/AddLife.h"

AddLife::AddLife(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setStandAble(true);
	setInitPosition(position);
    setTextureForObject(AssetsManager::instance().getTexture(0));
}

//void AddLife::addToLife(Player robot)
//{
//	robot.addLife();
//}