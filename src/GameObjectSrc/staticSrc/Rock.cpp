
#include "GameObject/staticInclude/Rock.h"
#include "GameObject/movingInclude/Robot.h"

Rock::Rock(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setInitPosition(position);
    setStandAble(false);
    setTextureForObject(AssetsManager::instance().getTexture(ROCK));
}

void Rock::handleCollision(GameObject& gameObject)
{
	//std::cout << "Rock collided with GameObject" << std::endl;
}

void Rock::handleCollision(Robot& robot)
{
	std::cout << "Rock collided with Robot" << std::endl;
	robot.getShape().setPosition((robot.getFirstPosition()));

	delete this;
}
