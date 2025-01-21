#include "Window.h"

Window::Window()
	: m_window(sf::VideoMode(screenWidth, screenHeight), "Bomber Man", sf::Style::Close | sf::Style::Titlebar)
{
	m_window.setFramerateLimit(60);

	m_gameBackground.setPosition(0, 0);
	m_gameBackground.setSize(sf::Vector2f(screenWidth, screenHeight));
	m_gameBackground.setTexture(AssetsManager::instance().getTexture(MAIN));
	m_gameBackground.setTextureRect(sf::IntRect(0,0, AssetsManager::instance().getTexture(MAIN)->getSize().x ,
		AssetsManager::instance().getTexture(MAIN)->getSize().y));

}

void Window::printWindow()
{
    m_window.clear(sf::Color::Red);
	m_window.draw(m_gameBackground);
}
sf::RenderWindow& Window::getRenderWindow()
{
	return m_window;
}
bool Window::isOpen()
{
    return m_window.isOpen();
}
void Window::clear()
{
	m_window.clear();
}

void Window::display()
{
	m_window.display();
}

void Window::draw(sf::RectangleShape& sprite)
{
	m_window.draw(sprite);
}

void Window::close()
{
	m_window.close();
}


bool Window::pollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
}

sf::Vector2f Window::mapPixelToCoords(const sf::Vector2i& vec) const
{
	return m_window.mapPixelToCoords(vec);
}