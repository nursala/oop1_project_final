#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Assets/AssetsManger.h"

class Robot;
class Wall;
class Guard;
class Rock;
class Door;

class GameObject 
{
public:
    GameObject() = default;
	virtual ~GameObject() = default;


    sf::Vector2f getInitPosition() const;
    //sf::Texture* getTexture() const;
    void draw(sf::RenderWindow& window);
    void setTextureForObject(sf::Texture* texture);
    void setInitPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    sf::Vector2f getSize() const;
	sf::RectangleShape& getShape() { return m_shape; }
    sf::FloatRect getObjBound() const;

	virtual void handleCollision(GameObject& ) = 0;
    virtual void handleCollision(Robot&) = 0;   
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Guard&) = 0;
	virtual void handleCollision(Rock&) = 0;
    virtual void handleCollision(Door&) = 0;
private:
    sf::Vector2f m_initPosition;
    sf::RectangleShape m_shape;
};
