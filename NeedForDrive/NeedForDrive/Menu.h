#pragma once
#include "Engine.h"
#define MAX_MENU_ITEMS 3
#define MAX_SETTINGS_ITEMS 3
#define MAX_RESOLUTION_ITEMS 3

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
private:
	bool settings;
	bool fullscreen;
	int settingsIndex;
	int itemIndex;
	int settingsResolution;
	resolution resolutions[MAX_RESOLUTION_ITEMS];
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::Texture backgroundImage;
	sf::Sprite background;
	sf::Font font;
	sf::Text menuItem[MAX_MENU_ITEMS];
	sf::Text settingsItem[MAX_SETTINGS_ITEMS];
};