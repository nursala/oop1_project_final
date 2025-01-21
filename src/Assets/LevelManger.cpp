#include <iostream>
#include <fstream>
#include <Assets/LevelManger.h>

LevelManger::LevelManger()
    : m_currentLevel(0), m_levelTime(0), m_levelCount(0), m_column(0), m_row(0)
{
    loadPlayList();
    loadLevel();
}

void LevelManger::loadPlayList()
{
    std::ifstream playList("Playlist.txt");
    if (!playList.is_open())
    {
        std::cerr << "cannot load playLest\n";
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (std::getline(playList, line))
    {
        m_levelCount++;
        std::cout << line << std::endl; // Displaying each line of the file
        m_playList.push_back(line);
    }
	std::cout << m_levelCount << std::endl;


    playList.close();
}

void LevelManger::loadLevel()
{
    std::ifstream file(m_playList[m_currentLevel]); // Open file
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open level file!" << std::endl;
        return;
    }
    else
    {
        std::cout << m_playList[m_currentLevel];
    }
    file >> m_row >> m_column >> m_levelTime;

    std::cout << m_row << " " << m_column << " " << m_levelTime << std::endl;

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        m_levelsData.push_back(line);
    }
}

const std::vector<std::string>& LevelManger::getLevelData() const
{
    return m_levelsData;
}

void LevelManger::loadSingleLevel()
{
    if (m_currentLevel >= m_levelsData.size()) {
        std::cerr << "Error: No more levels to load!" << std::endl;
        return;
    }

    // Print the level data
    for (const auto& line : m_levelsData) {
        std::cout << line << std::endl;
    }
}

int LevelManger::getTime() const { return m_levelTime; }
int LevelManger::getRow() const { return m_row; }
int LevelManger::getColumn() const { return m_column; }
int LevelManger::getLevelCount() const { return m_levelCount; }

int LevelManger::getLevel() const
{
    return m_currentLevel;
}

void LevelManger::prepareNewLevel()
{
    m_currentLevel++;

    if (m_currentLevel < m_levelCount)
    {
        m_column = 0;
        m_row = 0;
        m_levelsData.clear();
        loadLevel();
    }
   
}