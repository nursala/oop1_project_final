#include "GameObject/staticInclude/Door.h"

Door::Door(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setInitPosition(position);
	setStandAble(true);
    setTextureForObject(AssetsManager::instance().getTexture(DOOR));
}

void Door::handleCollision(GameObject& gameObject)
{
	//std::cout << "GameObject collided with Door" << std::endl;
}

void Door::handleCollision(Guard& guard)
{
	std::cout << "Guard collided with Door" << std::endl;
}

void Door::handleCollision(Robot& robot)
{
	std::cout << "Robot collided with Door" << std::endl;
}

