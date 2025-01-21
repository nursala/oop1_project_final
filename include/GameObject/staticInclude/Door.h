#pragma once

#include "GameObject/StaticObject.h"

class Door : public StaticObject
{
public:
	Door(sf::Vector2f position, sf::Vector2f size);
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Robot& robot) override;

private:

};


