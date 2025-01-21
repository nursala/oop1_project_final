#include "GameObject/staticInclude/Wall.h"
#include "GameObject/movingInclude/Robot.h"

Wall::Wall(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
    setInitPosition(position);
    setStandAble(false);
    setTextureForObject(AssetsManager::instance().getTexture(WALL));
}

//void Wall::handleCollision(GameObject& other)
//{
//	if (&other == this)
//		return;
//
//	other.handleCollision(*this);
//}

void Wall::handleCollision(Guard& guard)
{
	//std::cout << "Guard collided with Wall" << std::endl;
}

void Wall::handleCollision(GameObject& gameObject)
{
	//std::cout << "GameObject collided with Wall" << std::endl;
}

void Wall::handleCollision(Robot& robot)
{
	robot.getShape().setPosition(robot.getFirstPosition());
	std::cout << "Robot collided with Wall" << std::endl;
}