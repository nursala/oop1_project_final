#include "StatusBar.h"
#include "Controller.h"

// Constructor
StatusBar::StatusBar() {
    // Initialize background
    m_background.setPosition(sf::Vector2f(0, 0));
    m_background.setFillColor(sf::Color(0, 0, 0, 50));  // Semi-transparent black
    m_background.setSize(sf::Vector2f(screenWidth, TILE_STATUS_BAR_SIZE + MARGIN * 2));

    // Load font
    if (!m_font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        throw std::runtime_error("Failed to load font");
    }

    // Initialize default values for the status bar
    setForStatusBar();
    initButtons();
}

// Initialize buttons
void StatusBar::initButtons() {
    float buttonWidth = TILE_STATUS_BAR_SIZE, buttonHeight = TILE_STATUS_BAR_SIZE, buttonSpacing = MARGIN;
    float startX = screenWidth - MARGIN - buttonWidth, startY = m_background.getGlobalBounds().height / 2;

    // Add buttons for Home, Pause, and Sound
    m_buttons.emplace_back(Button(sf::Vector2f(startX, startY), sf::Vector2f(buttonWidth, buttonHeight)));
    m_buttons.emplace_back(Button(sf::Vector2f(startX - (buttonWidth + buttonSpacing), startY), sf::Vector2f(buttonWidth, buttonHeight)));
    m_buttons.emplace_back(Button(sf::Vector2f(startX - 2 * (buttonWidth + buttonSpacing), startY), sf::Vector2f(buttonWidth, buttonHeight)));

    // Set textures for buttons
    m_buttons[static_cast<int>(BoardButtonType::Home)].setTexture(AssetsManager::instance().getTexture(HOME));
    m_buttons[static_cast<int>(BoardButtonType::pause)].setTexture(AssetsManager::instance().getTexture(PAUSE));
    m_buttons[static_cast<int>(BoardButtonType::sound)].setTexture(AssetsManager::instance().getTexture(SOUNDON));
}

// Set up the status bar
void StatusBar::setForStatusBar() {
    setLives(3);
    setTime(0);
    setScore(0);
    setGifts(0);
    setLevel(1);
}

// Draw the status bar
void StatusBar::draw(sf::RenderWindow& window) const {
    // Draw background
    window.draw(m_background);

    // Draw buttons
    for (const auto& button : m_buttons) {
        button.printButton(window);
    }

    // Draw each status element (shape and text)
    for (int i = 0; i < 5; ++i) {
        window.draw(m_shape[i]);
        window.draw(m_text[i]);
    }
}

// Helper method to set status elements (text and texture)
void StatusBar::setStatusElement(int index, const std::string& text, const sf::Texture* texture, float posX) {
    initializeText(m_text[index], ":" + text, posX + TILE_STATUS_BAR_SIZE + BETWEEN_TEXTURE_AND_TEXT, MARGIN);
    initializeTexture(m_shape[index], texture, posX, MARGIN);
}

// Setters
void StatusBar::setLives(int lives) {
    setStatusElement(0, std::to_string(lives), AssetsManager::instance().getTexture(MAIN), MARGIN);
}

void StatusBar::setTime(int time) {
    secondToNormalTime(time);
    setStatusElement(1, m_tmpMin + ":" + m_tmpSec, AssetsManager::instance().getTexture(MAIN), ELEMENT_WIDTH * 1);
}

void StatusBar::setScore(int score) {
    setStatusElement(2, std::to_string(score), AssetsManager::instance().getTexture(MAIN), ELEMENT_WIDTH * 2);
}

void StatusBar::setGifts(int gift) {
    setStatusElement(3, std::to_string(gift), AssetsManager::instance().getTexture(MAIN), ELEMENT_WIDTH * 3);
}

void StatusBar::setLevel(int level) {
    setStatusElement(4, std::to_string(level), AssetsManager::instance().getTexture(MAIN), ELEMENT_WIDTH * 4);
}

// Helper methods
void StatusBar::initializeText(sf::Text& text, const std::string& content, float posX, float posY) {
    text.setFont(m_font);
    text.setCharacterSize(CHARSIZE);
    text.setFillColor(sf::Color::White);
    text.setString(content);
    text.setPosition(posX, posY);
}

void StatusBar::initializeTexture(sf::RectangleShape& shape, const sf::Texture* texture, float posX, float posY) {
    shape.setTexture(texture);
    shape.setPosition(posX, posY);
    shape.setSize(sf::Vector2f(TILE_STATUS_BAR_SIZE, TILE_STATUS_BAR_SIZE));
}

void StatusBar::secondToNormalTime(int seconds) {
    m_minutes = seconds / 60;
    m_seconds = seconds % 60;

    m_tmpMin = (m_minutes < 10 ? "0" : "") + std::to_string(m_minutes);
    m_tmpSec = (m_seconds < 10 ? "0" : "") + std::to_string(m_seconds);
}

// Event handling
void StatusBar::handleClick(const sf::Event& event, Controller& controller) {
    if (m_buttons[static_cast<int>(BoardButtonType::Home)].isContain(event)) {
        controller.updatePage(ScreenType::HomePage);
    }
    else if (m_buttons[static_cast<int>(BoardButtonType::sound)].isContain(event)) {
        if (AssetsManager::instance().isPlaying(SoundType::RUNNING_TIME)) {
            AssetsManager::instance().pause(SoundType::RUNNING_TIME);
            m_buttons[static_cast<int>(BoardButtonType::sound)].setTexture(AssetsManager::instance().getTexture(SOUNDOFF));
        }
        else {
            AssetsManager::instance().playSound(SoundType::RUNNING_TIME);
            m_buttons[static_cast<int>(BoardButtonType::sound)].setTexture(AssetsManager::instance().getTexture(SOUNDON));
        }
    }
    else if (m_buttons[static_cast<int>(BoardButtonType::pause)].isContain(event)) {
        controller.updatePage(ScreenType::Pause);
    }
}

void StatusBar::handleHover(const sf::Vector2f& location) {
    for (auto& button : m_buttons) {
        if (button.isHover(location)) {
            button.setColor(sf::Color(167, 167, 175));  // Light gray on hover
        }
        else {
            button.setColor(sf::Color::White);  // Default color
        }
    }
}

void StatusBar::processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller) {
    switch (event.type) {
    case sf::Event::MouseButtonReleased:
        handleClick(event, controller);
        break;
    default:
        handleHover(mouseLocation);
        break;
    }
}

// Update method
void StatusBar::update(int level , int robot) {
    setLevel(level);
    if (!AssetsManager::instance().isPlaying(SoundType::RUNNING_TIME)) {
        m_buttons[static_cast<int>(BoardButtonType::sound)].setTexture(AssetsManager::instance().getTexture(SOUNDOFF));
    }
    else {
        m_buttons[static_cast<int>(BoardButtonType::sound)].setTexture(AssetsManager::instance().getTexture(SOUNDON));
    }
    setLives(robot);
}

