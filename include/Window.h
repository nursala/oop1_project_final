#pragma once
#include <SFML/Graphics.hpp>
#include "Assets/AssetsManger.h"
#include "Macros.h"

class Window
{
public:
	Window();
    void printWindow();
    sf::RenderWindow& getRenderWindow();
    bool isOpen();
    void clear();
    void display();

    void draw(sf::RectangleShape& sprite);


	void close();
	void handleEvent();
    bool pollEvent(sf::Event& event);
    sf::Vector2f mapPixelToCoords(const sf::Vector2i& vec) const;
	sf::Event getEvent() { return m_event; }

private:
    sf::RenderWindow m_window;
    sf::RectangleShape m_gameBackground;
	sf::Event m_event;
};