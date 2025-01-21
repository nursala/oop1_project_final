#pragma once

#include"GameObject/StaticObject.h"

class Robot;
class Guard;
class Wall : public StaticObject
{
public:
	Wall(sf::Vector2f position, sf::Vector2f size);

	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
private:



};


