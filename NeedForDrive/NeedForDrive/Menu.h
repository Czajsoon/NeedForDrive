#pragma once
#include "Engine.h"
#include "GameSettings.h"
#include "Game.h"
#include "Controlls.h"
#define MAX_MENU_ITEMS 3
#define MAX_SETTINGS_ITEMS 3
#define MAX_RESOLUTION_ITEMS 3
#define MAX_CONTROLLS_ITEMS 6
#define MAX_PLAYERS 3


/*!
* \brief Struktura przechowujaca rozdzielczosc (width*height).
*/


struct resolution {
	int width;
	int height;
};


/*!
* \brief Klasa, ktora zawiera konstruktor oraz destruktur glownego Menu, a takze teksturki, muzyke oraz dzwieki w glownym menu wraz ze sterowaniem po nim.
*
*/

class Menu {
public:
	Menu(int height, int width);
	~Menu();
	void drawMenu(sf::RenderWindow& window);
	void moveUP();
	void moveDOWN();
	void performAction(sf::RenderWindow& window);
	PlayersSett playersSet[MAX_PLAYERS];
	Game* gameScreen;
private:
	bool mainMenu;
	bool settings;
	bool control;
	bool gameSet;
	bool game;
	int heightW;
	int widthW;
	int playersAmount;
	int settingsIndex;
	int itemIndex;
	int controllIndex;
	int playerIndex;
	int settingsResolution;
	GameSettings* gameSettings;
	sf::Texture gameMap;
	resolution resolutions[MAX_RESOLUTION_ITEMS];
	sf::SoundBuffer mainThermeMusicBuffer;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::Sound mainThermeMusic;
	sf::Texture backgroundImage;
	sf::Sprite background;
	sf::Font font;
	sf::Text menuItem[MAX_MENU_ITEMS];
	sf::Text controllItems[MAX_CONTROLLS_ITEMS];
	sf::Text settingsItem[MAX_SETTINGS_ITEMS];
};