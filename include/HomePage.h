#pragma once
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

#include "Button.h"


class Controller;

class HomePage
{
public:
    HomePage();
    void draw(sf::RenderWindow& window);
    void processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller);
    void handleClick(const sf::Event& event, Controller& controller);
    void handleMenuClick(const sf::Event& event, Controller& controller);
    void drawMenu(sf::RenderWindow& window);
    void handleHover(const sf::Vector2f& location);

private:
    void setHelpScreen() ;
    void initButtons();

    sf::RectangleShape m_helpBackground;
    sf::RectangleShape m_Background;

    PageStatus m_pageStatus;

    std::vector<Button> m_buttons; // Store buttons in a vector
};
