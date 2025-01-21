#include "Button.h"

Button::Button()
	: m_button(sf::Vector2f(10,10))
{
}

Button::Button(sf::Vector2f buttonPos, sf::Vector2f buttonSize, std::string buttonName , int textSize )
	: m_buttonSize(buttonSize)
{
	m_button.setSize(m_buttonSize);
	m_button.setTexture(AssetsManager::instance().getTexture(BUTTON));
	m_button.setTextureRect(sf::IntRect(0, 0, AssetsManager::instance().getTexture(BUTTON)->getSize().x, AssetsManager::instance().getTexture(BUTTON)->getSize().y));
	m_button.setPosition(buttonPos);
	m_button.setOrigin(m_buttonSize.x / 2, m_buttonSize.y / 2);
	m_buttonText.setFont(*AssetsManager::instance().getFont());
	m_buttonText.setString(buttonName);
	m_buttonText.setCharacterSize(textSize);
	m_buttonText.setPosition(sf::Vector2f(m_button.getPosition().x, m_button.getPosition().y - m_buttonText.getGlobalBounds().height/2));
	m_buttonText.setOrigin(m_buttonText.getGlobalBounds().width / 2, m_buttonText.getGlobalBounds().height / 2);


}

void Button::setButtonSize(sf::Vector2f buttonSize)
{
	m_button.setSize(buttonSize);
}

void Button::setScaleButon(sf::Vector2f scale)
{
	m_button.setScale(scale);
}

void Button::printButton(sf::RenderWindow& window)const
{
	
	window.draw(m_button);
	window.draw(m_buttonText);
}

bool Button::contain(sf::Vector2f location) 
{
	return m_button.getGlobalBounds().contains(location);
}

void Button::changeText(std::string text)
{
	
	m_buttonText.setString(text);
	m_buttonText.setOrigin(m_buttonText.getGlobalBounds().width / 2, m_buttonText.getGlobalBounds().height / 2);
}

void Button::setTexture(sf::Texture* texture)
{
	m_button.setTexture(texture);
	m_button.setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
}

sf::Vector2f Button::getSize() const
{
	return m_button.getSize();
}
bool Button::isHover(sf::Vector2f location) const
{
	return m_button.getGlobalBounds().contains(location);
}
bool Button::isContain(sf::Event event) const
{
	return m_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void Button::setColor(sf::Color color)
{
	m_button.setFillColor(color);

}