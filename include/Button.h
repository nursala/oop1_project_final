#pragma once
#include <SFML/Graphics.hpp>
#include "Assets/AssetsManger.h"

#include <string>
#include "Macros.h"

class Button
{
public:
	Button();
	Button(sf::Vector2f buttonPos, sf::Vector2f buttonSize, std::string buttonName = "", int textSize = 0);

	void setScaleButon(sf::Vector2f scale);
	void printButton(sf::RenderWindow& window) const;
	bool contain(sf::Vector2f location);
	void changeText(std::string);

	void setTexture(sf::Texture* texture);

	sf::Vector2f getSize() const;


	bool isHover(sf::Vector2f location) const;

	bool isContain(sf::Event event) const;

	void setColor(sf::Color color);
	
private:
	void setButtonSize(sf::Vector2f buttonSize);

	sf::Vector2f m_buttonSize;
	sf::RectangleShape m_button;
	sf::Text m_buttonText;
};


