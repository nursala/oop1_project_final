#include <Pause.h>
#include "Controller.h"

Puase::Puase()
{
	m_background.setFillColor(sf::Color(100, 101, 61, 200));

	m_background.setPosition(0, 0);
	m_background.setSize(sf::Vector2f(screenWidth, screenHeight));


	m_button = Button(sf::Vector2f(screenWidth / 2, screenHeight / 2), sf::Vector2f(screenWidth / 10, screenHeight / 10), " ", 0);
	m_button.setTexture(AssetsManager::instance().getTexture(PLAY));
}

void Puase::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	m_button.printButton(window);
}

void Puase::processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller)
{

		switch (event.type)
		{
		case sf::Event::MouseButtonReleased:
		{
			handleClick(event, controller);
			break;
		}
		case sf::Event::MouseMoved:
		{
			handleHover(mouseLocation);
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Enter)
				AssetsManager::instance().playSound(RUNNING_TIME);
				controller.updatePage(ScreenType::Game);
		}
		default:
			break;
		}
	


}
void Puase::handleClick(const sf::Event& event, Controller& controller)
{
	if (m_button.isContain(event))
	{
		AssetsManager::instance().playSound(RUNNING_TIME);
		controller.updatePage(ScreenType::Game);
	}
}

void Puase::handleHover(const sf::Vector2f& location)
{
	
		if (m_button.isHover(location))
			m_button.setTexture(AssetsManager::instance().getTexture(PLAY));
		else
			m_button.setTexture(AssetsManager::instance().getTexture(TAPPLAY));
	
}