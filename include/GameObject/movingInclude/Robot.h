#pragma once

#include "GameObject/MovingObject.h"
#include <Board.h>


class Robot : public MovingObject
{
public:
	Robot(sf::Vector2f position, sf::Vector2f size);

	void move(sf::Time deltaTime, Board& board);

	//void handleColllision(GameObject&) override;

	void updateLives();

	int getLives();

	virtual void handleCollision(GameObject& gameObject);
	virtual void handleCollision(Wall& wall) {};
	virtual void handleCollision(Rock& rock) {};
	virtual void handleCollision(Door& door);
	virtual void handleCollision(Guard& guard);
private:
	int m_lives;
	int m_score;
	bool m_hasGift;

};