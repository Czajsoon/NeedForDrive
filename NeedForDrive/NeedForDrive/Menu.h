#pragma once
#include "Engine.h"
#include "GameSettings.h"
#include "Controlls.h"
#define MAX_MENU_ITEMS 3
#define MAX_SETTINGS_ITEMS 3
#define MAX_RESOLUTION_ITEMS 3
#define MAX_CONTROLLS_ITEMS 6
#define MAX_PLAYERS 3

struct resolution {
	int width;
	int height;
};


class Menu {
public:
	Menu(int height, int width);
	~Menu();
	void drawMenu(sf::RenderWindow& window);
		void moveUP();
	void moveDOWN();
	void performAction(sf::RenderWindow& window);
	Controlls controlls[MAX_PLAYERS];
private:
	bool settings;
	bool control;
	bool gameSet;
	int settingsIndex;
	int itemIndex;
	int controllIndex;
	int playerIndex;
	int settingsResolution;
	GameSettings* gameSettings;
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