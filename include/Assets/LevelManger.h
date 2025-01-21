#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>


class LevelManger
{
public:
    LevelManger();
    void loadPlayList();
    void loadLevel();
    const std::vector<std::string>& getLevelData() const;
    void loadSingleLevel();
    int getTime() const;
    int getRow() const;
    int getColumn() const;
    int getLevelCount() const;

	int getLevel() const;

    void prepareNewLevel();

private:
    std::vector<std::string> m_playList;
    std::vector<std::string> m_levelsData; // Stores level data
    int m_currentLevel;    // Current level index
    int m_levelTime; // Time limit for the current level
    int m_levelCount;      // Total number of levels
    int m_column;          // Level column count
    int m_row;             // Level row count

};
