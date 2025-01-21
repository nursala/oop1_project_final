#include "GameObject/movingInclude/Robot.h"
#include <iostream>

Robot::Robot(sf::Vector2f position, sf::Vector2f size) : m_lives(3)
{
    setSize(sf::Vector2f{ size.x - 10, size.y - 10 });
    setInitPosition(position);
    setTextureForObject(AssetsManager::instance().getTexture(PLAYER));
}

void Robot::move(sf::Time deltaTime, Board& board)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        directionMove({ 0.f, -1.f });
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        directionMove({ 0.f, 1.f });
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        directionMove({ -1.f, 0.f });
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        directionMove({ 1.f, 0.f });
    }
    else
    {
        directionMove({ 0.f, 0.f });
    }

    setScaleForObject();

    // Move the robot using SFML's move method
    sf::Vector2f offset = getDirection() * getSpeed() * deltaTime.asSeconds();
    if (isValidMove(getShape().getPosition() + offset))
    {
		setFirstPosition(getShape().getPosition());
		getShape().move(offset);
	}
}

void Robot::updateLives()
{
    m_lives--;
}

int Robot::getLives()
{
    return m_lives;
}

void Robot::handleCollision(GameObject& object)
{
	if (&object == this)
		return;

	object.handleCollision(*this);
}



void Robot::handleCollision(Door& door)
{
	std::cout << "Robot collided with Door" << std::endl;
}

void Robot::handleCollision(Guard& guard)
{
    updateLives();
}




