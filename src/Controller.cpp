#include "Controller.h"
#include "Assets/AssetsManger.h"

Controller::Controller() :m_currPage(ScreenType::HomePage)
{
	AssetsManager::instance().playSound(RUNNING_TIME);
	initializeScreen(m_loss, GAMEOVER);
	initializeScreen(m_win, WIN);
}

void Controller::initializeScreen(sf::RectangleShape& shape, Texture texture)
{
	sf::Texture* textureToSet = AssetsManager::instance().getTexture(texture);
	shape.setPosition(0, 0);
	shape.setSize(sf::Vector2f(screenWidth, screenHeight));
	shape.setTexture(textureToSet);
	shape.setTextureRect(sf::IntRect(0, 0,
		textureToSet->getSize().x,
		textureToSet->getSize().y));
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		processEvents(); //events
		update(); //update game logic and state
		render(); //draw
	}

}
void Controller::exit()
{
	m_window.close();
}

void Controller::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}
		sf::Vector2f ml = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
		switch (m_currPage)
		{
		case ScreenType::HomePage:
			m_HomePage.processEvents(event, ml, *this);
			break;
		case ScreenType::Game:
			m_board.processEvents(event, ml, *this);
			break;
		case ScreenType::Pause:
			m_pause.processEvents(event, ml, *this);
			break;
		default:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				m_window.close();
			break;
		}
	}
}


void Controller::render()
{
	m_window.clear();
	drawCurrPage();
	m_window.display();
}

void Controller::drawCurrPage()
{
	//m_window.printWindow();/// remove
	switch (m_currPage)
	{
	case ScreenType::HomePage:
		m_HomePage.draw(m_window.getRenderWindow());
		break;
	case ScreenType::Game:
		m_board.draw(m_window.getRenderWindow());
		break;
	case ScreenType::Pause:
		m_board.draw(m_window.getRenderWindow());//efect
		m_pause.draw(m_window.getRenderWindow());
		break;
	case ScreenType::GAMEOVER:
		m_window.draw(m_loss);
		break;

	case ScreenType::WIN:

		m_window.draw(m_win);
		break;
	default:
		break;
	}
}
void Controller::updatePage(ScreenType type)
{
	m_currPage = type;
}

ScreenType Controller::getScreenType() const
{
	return m_currPage;
}

void Controller::update()
{
	if(m_currPage == ScreenType::Game)
	m_board.update(*this);
}
void Controller::pause()
{
	AssetsManager::instance().pause(RUNNING_TIME);
	updatePage(ScreenType::Pause);
}

void Controller::nextLevel()
{
	AssetsManager& asset = AssetsManager::instance();
	asset.loadNextLevel();

	if (asset.getLevel() < asset.getLevelCount())
	{
		m_board.loadLevel();
	}
	else
	{
		asset.playSound(SoundType::WIN_TIME);
		updatePage(ScreenType::WIN);
	}
}