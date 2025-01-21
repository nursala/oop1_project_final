#pragma once
#include <SFML/Graphics.hpp> 
#include "Board.h"
#include "Window.h"
#include "HomePage.h"
#include <Pause.h>


class HomePage;
class Controller
{
public:
    Controller();
    void initializeScreen(sf::RectangleShape& shape, Texture texture);
    void run();

    void exit();

    void processEvents();

    void render();

    void drawCurrPage();

    void updatePage(ScreenType type);


    ScreenType getScreenType() const;

    void update();

    void pause();

    void nextLevel();




private:
    HomePage m_HomePage;
	Puase m_pause;
    Board m_board;
    Window m_window;
    sf::RectangleShape m_loss;
    ScreenType m_currPage;

    sf::RectangleShape m_win;
};
