#include "GameObject/GameObject.h"

sf::Vector2f GameObject::getInitPosition() const
{
	return m_initPosition;
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void GameObject::setTextureForObject(sf::Texture* texture)
{

	m_shape.setTexture(texture);
	m_shape.setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
}

void GameObject::setInitPosition(sf::Vector2f position)
{
	m_initPosition = position;
	m_shape.setPosition(m_initPosition);
}

void GameObject::setSize(sf::Vector2f size)
{
	m_shape.setSize(size);
	m_shape.setOrigin(m_shape.getSize().x / 2, m_shape.getSize().y / 2);
}

sf::Vector2f GameObject::getSize() const
{
	return m_shape.getSize();
}

sf::FloatRect GameObject::getObjBound() const 
{
	return m_shape.getGlobalBounds();
}