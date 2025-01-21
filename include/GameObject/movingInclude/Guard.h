#pragma once

#include "GameObject/MovingObject.h"

#include <Board.h>

class Guard : public MovingObject
{
public:
	Guard(sf::Vector2f position, sf::Vector2f size);

	void move(sf::Time deltaTime, Board& board);

	sf::Vector2f generateDirection(sf::Time deltaTime, const sf::Vector2f& robot);

	//void move(sf::Time deltaTime);

	//killGuard(sf::Vector2f position);

	//sf::Vector2f generateDirection(sf::Time deltaTime);

	sf::Vector2f findOptimalMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& currentPosition, sf::Time deltaTime, const sf::Vector2f& robot);

	//sf::Vector2f findOptimalMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& currentPosition, sf::Time deltaTime);

	sf::Vector2f findAnyValidMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& currentPosition, sf::Time deltaTime);

	virtual void handleCollision(GameObject&) ;
	virtual void handleCollision(Robot& robot) ;
	virtual void handleCollision(Wall& wall) ;
	virtual void handleCollision(Guard& guard) ;
	virtual void handleCollision(Rock& rock);
	virtual void handleCollision(Door& door);
private:
	int m_IQLevel;
	int m_goodstep;


};