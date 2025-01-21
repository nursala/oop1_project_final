#pragma once

#include "GameObject/StaticObject.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f position, sf::Vector2f size);

	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Robot& robot) override;
private:
};


