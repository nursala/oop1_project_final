#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <SFML/Audio.hpp>


const float screenWidth = 1920;
const float screenHeight = 1080;

const float MARGIN = screenHeight * 0.02f; // 2% of screen height
const float BAR_HEIGHT = screenHeight * 0.05f; // 5% of screen height for bar size
const float BoardSize = std::min(screenWidth, screenHeight) * 0.8f;  // Ensure square board
const float TILE_STATUS_BAR_SIZE = BoardSize * 0.05f;

const sf::Vector2f BoardViewPosition(
	(screenWidth - BoardSize) / 2,
	(screenHeight - BoardSize) / 2
);

const sf::Vector2f BoardViewSize(BoardSize, BoardSize);  // Ensure square size
const int NUM_OF_ELMENTS_AT_STATUS_BAR = 7;
const float ELEMENT_WIDTH = screenWidth / NUM_OF_ELMENTS_AT_STATUS_BAR;
const float BETWEEN_TEXTURE_AND_TEXT = 0.005 * screenWidth;
const int CHARSIZE = 0.02 * screenWidth;

enum Texture
{
	PLAYER,
	ENEMY,
	WALL,
	DOOR,
	ROCK,
	MAIN,
	BUTTON,
	TAPBUTTON,
	PLAY,
	TAPPLAY,
	GAMEOVER,
	BOARDBACKGROUND,
	PAUSE,
	SOUNDON,
	HOME,
	SOUNDOFF,
	TAPSOUNDOFF,
	TAPPAUSE,
	TAPSOUNDON,
	TAPHOME,
	WIN,
	BACK,
	NUM_OF_TEXTURES
};

const std::map<int, std::string> TexturePath{

	{PLAYER, "player.png"},
	{ENEMY, "enemy.png"},
	{WALL, "wall.png"},
	{DOOR, "door.png"},
	{ROCK, "rock.png"},
	{MAIN, "background.jpg"},
	{BUTTON, "button.png"},
	{TAPBUTTON, "tapbutton.png" },
	{PLAY, "play.png"},
	{TAPPLAY, "tapplay.png"} ,
	{GAMEOVER, "gameover.jpg"},
	{BOARDBACKGROUND, "boardbackground.jpeg"},

	{PAUSE, "pause.png"},
	{TAPPAUSE, "tappause.png"},
	{TAPSOUNDON, "tapsoundon.png"},
	{TAPHOME, "taphome.png"},
	{HOME, "home.png"},
	{SOUNDOFF, "soundoff.png"},
	{TAPSOUNDOFF, "tapsoundoff.png"},
	{SOUNDON, "soundon.png"},
	{WIN, "win.jpg"},
	{BACK, "back.png"},
};


enum SoundType {
	RUNNING_TIME,
	GAME_OVER_1,
	GAME_OVER_2,
	WIN_TIME
};

const std::map<int, std::string> SOUND_FILE =
{
	{RUNNING_TIME,  "running_time.ogg"},
{GAME_OVER_1, "1.mp3"},
	{GAME_OVER_2, "2.mp3"},
	   {WIN_TIME, "win.mp3"}
};

enum class ScreenType
{
	HomePage = 0,
	LevelMenu,
	Pause,
	Game,
	GAMEOVER,
	WIN
};

enum class PageStatus
{
	Menu,
	Help,
};
enum class HomeButtonType
{
	Start,
	Help,
	Exit
};
enum class StatusBarData {
	Lives,
	Time,
	Score,
	Gifts,
	Level,
};
enum class BoardButtonType
{
	sound = 0,
	pause,
	Home
};