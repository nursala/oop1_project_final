#include <algorithm> // For std::shuffle
#include <random>    // For random_device and mt19937
#include <vector>
#include <SFML/System.hpp> // Assuming you're using sf::Vector2f
#include <iostream>
#include "GameObject/movingInclude/Guard.h"

Guard::Guard(sf::Vector2f position, sf::Vector2f size) : m_IQLevel(rand() % 2), m_goodstep(0)
{
    setSize({ size.x - 10, size.y - 10 });
    setInitPosition(position);
    setTextureForObject(AssetsManager::instance().getTexture(ENEMY));
}

void Guard::move(sf::Time deltaTime, Board& board)
{
    sf::Vector2f bestMove = generateDirection(deltaTime, board.getRobot().getShape().getPosition());

    // Apply the best move
    sf::Vector2f offset = bestMove * getSpeed() * deltaTime.asSeconds();
    setFirstPosition(getShape().getPosition()); // Update the first position
    getShape().move(offset); // Move the guard if the new location is valid

}

sf::Vector2f Guard::generateDirection(sf::Time deltaTime, const sf::Vector2f& robot)
{
    if (m_goodstep >= 5) { // Reset good step counter periodically
        m_goodstep = 0;
    }
    // Possible movement directions
    std::vector<sf::Vector2f> possibleMoves = { {0,0},{1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    sf::Vector2f currentPosition = getShape().getPosition();
    int minDistanceSquared = INT_MAX; // To find the closest move
    sf::Vector2f bestMove = { 0, 0 };



    // Select the best move based on IQ level
    if (m_goodstep < m_IQLevel) {
        bestMove = findOptimalMove(possibleMoves, currentPosition, deltaTime, robot);
    }
    else {
        bestMove = findAnyValidMove(possibleMoves, currentPosition, deltaTime);
        std::cout << "Random move" << std::endl;
        std::cout << "x: " << bestMove.x << " y: " << bestMove.y << std::endl;

    }

    m_goodstep++; // Increment good step counter
    //setScaleForObject(); // Adjust visual scale if necessary
    return bestMove;
}

sf::Vector2f Guard::findOptimalMove(const std::vector<sf::Vector2f>& possibleMoves,
    const sf::Vector2f& currentPosition, sf::Time deltaTime,
    const sf::Vector2f& robot)
{
    sf::Vector2f bestMove = { 0, 0 };
    int minDistanceSquared = INT_MAX;

    for (const auto& dir : possibleMoves) {
        sf::Vector2f newLocation = currentPosition + dir * getSpeed() * deltaTime.asSeconds();
        int distanceSquared = pow(robot.x - newLocation.x, 2) + pow(robot.y - newLocation.y, 2);

        if (isValidMove(newLocation) && distanceSquared < minDistanceSquared) {
            minDistanceSquared = distanceSquared;
            bestMove = dir;
        }
    }
    return bestMove;
}



sf::Vector2f Guard::findAnyValidMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& currentPosition, sf::Time deltaTime)
{
    // Create a copy of the possible moves to shuffle
    std::vector<sf::Vector2f> shuffledMoves = possibleMoves;

    // Random number generator
    std::random_device rd;   // Seed
    std::mt19937 g(rd());    // Mersenne Twister generator

    // Shuffle the moves
    std::shuffle(shuffledMoves.begin(), shuffledMoves.end(), g);

    // Iterate through the shuffled moves to find a valid one
    for (const auto& dir : shuffledMoves) {
        sf::Vector2f newLocation = currentPosition + dir * getSpeed() * deltaTime.asSeconds();
        if (isValidMove(newLocation)) {
            return dir; // Return the first valid move
        }
    }

    std::cout << "No valid moves after checking all directions" << std::endl;
    return { 0, 0 }; // No valid moves
}

void Guard::handleCollision(GameObject& object)
{
    if (&object == this)
        return;

    object.handleCollision(*this);
}

void Guard::handleCollision(Robot& robot)
{
    setAllToInitial();
    robot.setAllToInitial();
}

void Guard::handleCollision(Wall& wall)
{
}

void Guard::handleCollision(Guard& guard)
{
    static bool collisionHandled = false;

    if (!collisionHandled) {

        // Reset the positions of both guards to their first positions
        this->getShape().setPosition(this->getFirstPosition());
        //guard.getShape().setPosition(guard.getFirstPosition());

        collisionHandled = true; // Mark collision as handled
    }
}

void Guard::handleCollision(Rock& rock)
{
}

void Guard::handleCollision(Door& door)
{
}