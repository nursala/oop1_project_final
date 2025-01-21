#include "GameObject/MovingObject.h"

sf::Vector2f MovingObject::getFirstPosition() const
{
	return m_firstPosition;
}

void MovingObject::setAllToInitial()
{
	getShape().setPosition(getInitPosition());
}

bool MovingObject::isThereCollision(const sf::Vector2f position)
{
	return false;
}

void MovingObject::setFirstPosition(const sf::Vector2f position)
{
	m_firstPosition = position;
}

void MovingObject::setObjPostion(sf::Vector2f position)
{
	getShape().setPosition(position);
}

void MovingObject::directionMove(sf::Vector2f direction)
{ 
	m_direction = direction;
}

float MovingObject::getSpeed() { return m_speed;}

sf::Vector2f MovingObject::getDirection() {return m_direction;}

bool MovingObject::isValidMove(const sf::Vector2f& position) const
{
	// Check if the position is within the board boundaries
	float leftBound = BoardViewPosition.x;
	float rightBound = BoardViewPosition.x + BoardViewSize.x - getSize().x;
	float topBound = BoardViewPosition.y;
	float bottomBound = BoardViewPosition.y + BoardViewSize.y - getSize().y;

	return position.x >= leftBound && position.x <= rightBound &&
		position.y >= topBound && position.y <= bottomBound;
}

void MovingObject::setScaleForObject()
{
	if (m_direction.x > 0)
	{
		getShape().setScale(1.f, 1.f);
	}
	else if (m_direction.x < 0)
	{
		getShape().setScale(-1.f, 1.f);
	}
}
