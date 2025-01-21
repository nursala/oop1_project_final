#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>


#include "StatusBar.h"
#include "GameObject/staticInclude/Wall.h"
#include "GameObject/movingInclude/Robot.h"
#include "GameObject/movingInclude/Guard.h"
#include "GameObject/staticInclude/Door.h"
#include "GameObject/staticInclude/Bomb.h"
#include "GameObject/staticInclude/Rock.h"

class Controller;

class Board
{
public:
	Board();
	void loadLevel();
	void updateStatusBar();
	void updateRobot(Controller& controller);
	void readBoard();
	//void readBoard();
	void processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller);


	//void handleClick(const sf::Event& event, Controller& controller);

	Robot& getRobot() const ;

	void draw(sf::RenderWindow& window);
	sf::Vector2f getPositionFromTile(size_t row, size_t col) const;
	void update(Controller& controller);
private:
	std::vector<std::unique_ptr<StaticObject>> m_staticObject;
	std::vector<std::unique_ptr<MovingObject>> m_movingObject;

	sf::RectangleShape m_boardView;
	StatusBar m_statusBar;
	sf::Vector2f m_tileSize;
	sf::Clock m_clock, m_movementClock;
	int m_remainingTime;

};