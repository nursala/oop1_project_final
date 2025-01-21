#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Macros.h"
#include "Button.h"
#include "Assets/AssetsManger.h"

class Controller;

class StatusBar {
public:
    StatusBar();
    ~StatusBar() = default;

    // Initialization methods
    void initButtons();
    void setForStatusBar();

    // Drawing methods
    void draw(sf::RenderWindow& window) const;
    void setStatusElement(int index, const std::string& text, const sf::Texture* texture, float posX);
    void drawMenu(sf::RenderWindow& window) const;

    // Setters for status bar values
    void setLives(int lives);  // Update the lives counter
    void setTime(int time);    // Update the time display
    void setScore(int score);  // Update the score
    void setGifts(int gift);   // Update the gift count
    void setLevel(int level);  // Update the level display

    // Event handling methods
    void handleClick(const sf::Event& event, Controller& controller);
    void handleHover(const sf::Vector2f& location);
    void processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller);

    void update(int level, int robot);

    // Update method

private:
    // Helper methods
    void initializeText(sf::Text& text, const std::string& content, float posX, float posY);
    void initializeTexture(sf::RectangleShape& shape, const sf::Texture* texture, float posX, float posY);
    void secondToNormalTime(int seconds);

    // Private members
    sf::Font m_font;  // Font for all text elements
    sf::Text m_text[5];  // Text elements (e.g., lives, time, score)
    sf::RectangleShape m_shape[5];  // Icon shapes (e.g., heart for lives, clock for time)
    sf::RectangleShape m_background;  // Background rectangle

    // Time formatting variables
    int m_seconds = 0;
    int m_minutes = 0;
    std::string m_tmpSec = "00";
    std::string m_tmpMin = "00";

    std::vector<Button> m_buttons;  // Buttons for user interaction
    bool m_enabled = true;  // Whether the status bar is enabled
};