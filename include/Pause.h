#pragma once
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

#include "Button.h"


class Controller;

class Puase
{
public:
    Puase();
    void draw(sf::RenderWindow& window);
    void processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller);
    void handleClick(const sf::Event& event, Controller& controller);
    void handleHover(const sf::Vector2f& location);

private:


    sf::RectangleShape m_background;


    Button m_button; // Store buttons in a vector
};
