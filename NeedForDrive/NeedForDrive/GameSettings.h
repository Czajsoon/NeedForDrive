#pragma once
#include "Engine.h"
#include "Controlls.h"

struct Car {
	sf::Texture playersCar;
};

struct PlayersSet {
	int numberOfPlayer;
	Controlls contollsSet;
	sf::Texture playersCar;
};

class GameSettings {
public:
	GameSettings(int width,int height,bool& gameSett);
	~GameSettings();
	void draw(sf::RenderWindow& window);
	void performAction();
	void moveUP();
	void moveDOWN();
private:
	int itemIndex;
	bool* gameSet;
	Car cars[4];
	int numberOfPlayers;
	sf::Font font;
	sf::Text menuItems[5];
	sf::Sprite car;
};

