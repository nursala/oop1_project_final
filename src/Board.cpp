#include "Board.h"
#include "Controller.h"

Board::Board()
{
    m_remainingTime = AssetsManager::instance().getTime();
    // Initialize status bar with the starting time
    m_statusBar.setTime(m_remainingTime);

    // Calculate tile size based on the board dimensions
    float size = std::min(BoardViewSize.x / AssetsManager::instance().getRow(), BoardViewSize.y / AssetsManager::instance().getColumn());
    m_tileSize = sf::Vector2f(size, size);

    // Set up the board view
    m_boardView.setPosition(BoardViewPosition);
    m_boardView.setSize(BoardViewSize);
    m_boardView.setFillColor(sf::Color::Cyan);
    m_boardView.setTexture(AssetsManager::instance().getTexture(BOARDBACKGROUND));
    m_boardView.setTextureRect(sf::IntRect(0, 0,
        AssetsManager::instance().getTexture(BOARDBACKGROUND)->getSize().x,
        AssetsManager::instance().getTexture(BOARDBACKGROUND)->getSize().y));

    // Load the board
    readBoard();
}

void Board::loadLevel()
{
    m_movingObject.clear();
    m_staticObject.clear();
    float size = std::min(BoardViewSize.x / AssetsManager::instance().getRow(), BoardViewSize.y / AssetsManager::instance().getColumn());
    m_tileSize = sf::Vector2f(size, size);
    readBoard();
    m_remainingTime = AssetsManager::instance().getTime();
    // Initialize status bar with the starting time
    m_statusBar.setTime(m_remainingTime);

}

void Board::updateStatusBar() {
    // Update status bar time based on the elapsed time
    if (m_clock.getElapsedTime().asSeconds() >= 1.0f) {
        m_remainingTime--; // Decrease the remaining time
        m_statusBar.setTime(m_remainingTime);
        m_clock.restart();
    }

    // Handle game over condition if time runs out
    if (m_remainingTime <= 0) {
        std::cout << "Time's up! Game Over!" << std::endl;
        // Trigger game over logic (to be implemented in Controller or another class)
    }

    m_statusBar.update(AssetsManager::instance().getLevel() , getRobot().getLives() );
}

void Board::updateRobot(Controller& controller)
{
    const auto deltaTime = m_movementClock.restart();
    for (auto& movingObject : m_movingObject)
    {

        movingObject->move(deltaTime, *this);

        for (auto& otherMoving : m_movingObject) {
            if (movingObject != otherMoving &&
                movingObject->getObjBound().intersects(otherMoving->getObjBound())) {
                movingObject->handleCollision(*otherMoving);
            }
        }

        // Check collisions with static objects
        for (auto& staticObject : m_staticObject)
        {
            if (movingObject->getObjBound().intersects(staticObject->getObjBound())) {
                if (auto robot = dynamic_cast<Robot*>(movingObject.get())) {
                    if (auto door = dynamic_cast<Door*>(staticObject.get())) {
                        controller.nextLevel();
                        return;

					}

                   
                }
                movingObject->handleCollision(*staticObject);
                staticObject->handleCollision(*movingObject);
                

            }
        }
    }
}


void Board::readBoard() {
    const auto& map = AssetsManager::instance().getMap();

    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            sf::Vector2f position = getPositionFromTile(i, j);

            switch (map[i][j]) {
            case '#': m_staticObject.push_back(std::make_unique<Wall>(position, m_tileSize)); break;
            case '/': m_movingObject.push_back(std::make_unique<Robot>(position, m_tileSize)); break;
            case '!': m_movingObject.push_back(std::make_unique<Guard>(position, m_tileSize)); break;
            case 'D': m_staticObject.push_back(std::make_unique<Door>(position, m_tileSize)); break;
            case '@': m_staticObject.push_back(std::make_unique<Rock>(position, m_tileSize)); break;
            default: break; // Ignore unknown characters
            }
        }
    }
}

void Board::processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller) {
    m_statusBar.processEvents(event, mouseLocation, controller);

    switch (event.type) {
    case sf::Event::MouseButtonReleased:
        // Handle mouse button released event
        break;
    case sf::Event::MouseMoved:
        // Handle mouse moved event
        break;
    case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
            controller.pause(); // Pause the game on Escape key press
            break;
        case sf::Keyboard::N:
            controller.nextLevel(); // Next level on N key press
            break;
        case sf::Keyboard::S:default:
            break;
        }
        break;
    }
}

Robot& Board::getRobot() const
{
    for (auto& robot : m_movingObject)
    {
		return *dynamic_cast<Robot*>(robot.get());
    }
}

void Board::draw(sf::RenderWindow& window) {
    // Draw the board background
    window.draw(m_boardView);

    // Draw the status bar
    m_statusBar.draw(window);

    // Draw static objects
    for (const auto& object : m_staticObject) {
        object->draw(window);
    }

    // Draw moving objects
    for (const auto& object : m_movingObject) {
        object->draw(window);
    }
}

sf::Vector2f Board::getPositionFromTile(size_t row, size_t col) const {
    // Calculate position based on tile size and board position
    return sf::Vector2f(
        col * m_tileSize.x + m_boardView.getPosition().x,
        row * m_tileSize.y + m_boardView.getPosition().y
    );
}

void Board::update(Controller& controller) {
    if (controller.getScreenType() != ScreenType::Game) {
        return;
    }
    updateStatusBar();
    updateRobot(controller);

    if (m_remainingTime <= 0) {
        std::cout << "Time's up! Game Over!" << std::endl;
        AssetsManager::instance().pause(RUNNING_TIME);
        controller.updatePage(ScreenType::GAMEOVER);
        AssetsManager::instance().playSound(GAME_OVER_1);
        AssetsManager::instance().playSound(GAME_OVER_2);
        // Trigger game over logic (to be implemented in Controller or another class)
    }
}