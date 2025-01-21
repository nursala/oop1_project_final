#include "HomePage.h"
#include "Controller.h"




HomePage::HomePage():m_pageStatus(PageStatus::Menu)
{
	setHelpScreen();
	initButtons();
}


void HomePage::setHelpScreen() 
{
	m_helpBackground.setPosition(0, 0);
	m_helpBackground.setSize(sf::Vector2f(screenWidth, screenHeight));
	m_helpBackground.setFillColor(sf::Color::Black);

}
void HomePage::initButtons()
{
	float buttonWidth = 450, buttonHeight = 150, buttonSpacing = 20;
	float startX = screenWidth/2, startY = screenHeight/2;

	m_buttons.emplace_back(Button(sf::Vector2f(startX, startY), sf::Vector2f(buttonWidth, buttonHeight), "Play", 30));
	m_buttons.emplace_back(Button(sf::Vector2f(startX, startY + buttonHeight + buttonSpacing), sf::Vector2f(buttonWidth, buttonHeight), "How to Play", 30));
	m_buttons.emplace_back(Button(sf::Vector2f(startX, startY + 2 * (buttonHeight + buttonSpacing)), sf::Vector2f(buttonWidth, buttonHeight), "Exit", 30));

}

void HomePage::draw(sf::RenderWindow& window)
{
	switch (m_pageStatus)
	{
	case PageStatus::Help:
		window.draw(m_helpBackground);
		break;
	case PageStatus::Menu:
		drawMenu(window);
		break;
	default:
		break;
	}
}

void HomePage::processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller)
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
	default:
		break;
	}
}


void HomePage::handleClick(const sf::Event& event, Controller& controller)
{
	switch (m_pageStatus)
	{
	case PageStatus::Menu:
	{
		handleMenuClick(event, controller);
		break;
	}
	case PageStatus::Help:
	{
		m_pageStatus = PageStatus::Menu;
		break;
	}
	default:
		break;
	}
}

void HomePage::handleMenuClick(const sf::Event& event, Controller& controller)
{
	if (m_buttons[static_cast<int>(HomeButtonType::Start)].isContain(event))
	{
		m_buttons[static_cast<int>(HomeButtonType::Start)].changeText("Continue");

		controller.updatePage(ScreenType::Game);
	}

	else if (m_buttons[static_cast<int>(HomeButtonType::Help)].isContain(event))
	{
		//setBackgroundColor(sf::Color(255, 255, 255, 205));
		m_pageStatus = PageStatus::Help;
	}

	else if (m_buttons[static_cast<int>(HomeButtonType::Exit)].isContain(event))
	{
		controller.exit();
	}
}
void HomePage::drawMenu(sf::RenderWindow& window)
{
	for (auto& button : m_buttons)
	{
		button.printButton(window);
	}
}

void HomePage::handleHover(const sf::Vector2f& location)
{
	for (int i = 0; i < m_buttons.size(); ++i)
	{
		if (m_buttons[i].isHover(location))
			m_buttons[i].setTexture(AssetsManager::instance().getTexture(BUTTON));
		else
			m_buttons[i].setTexture(AssetsManager::instance().getTexture(TAPBUTTON));
	}
}
