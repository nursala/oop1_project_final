#pragma once

#include "GameObject/GameObject.h"

class StaticObject;
class Board;

class MovingObject : public GameObject
{
public:
	MovingObject() = default;
	virtual void move(sf::Time deltaTime , Board& board) = 0;
	sf::Vector2f getFirstPosition() const;
	void setAllToInitial();
	bool isThereCollision(const sf::Vector2f position);
	void setFirstPosition(const sf::Vector2f position);
	void setObjPostion(sf::Vector2f position);
	void directionMove(sf::Vector2f direction);
	float getSpeed();
	sf::Vector2f getDirection();
	bool isValidMove(const sf::Vector2f& position) const;
	void setScaleForObject();

	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Robot&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Guard&) {};
	virtual void handleCollision(Rock&) {};
	virtual void handleCollision(Door&) {};
	//virtual void handleCollision(StaticObject&) = 0;
	//virtual void handleCollision(MovingObject&) = 0;

private:
	sf::Vector2f m_firstPosition;
	//sf::Vector2f m_nextPosition;
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	float m_speed = 100.f;
};
