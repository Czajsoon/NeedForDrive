#pragma once
#include "Engine.h"
#include "Controlls.h"

struct Car {
	sf::Texture playersCar;
};

struct PlayersSet {
	int numberOfPlayer;
	int carNumber;
	Controlls contollsSet;
	sf::Sprite playersCar;
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
	int width;
	int height;
	int itemIndex;
	int currentPlayer;
	//int current;
	bool* gameSet;
	Car cars[3];
	PlayersSet playerSet[3];
	int numberOfPlayers;
	sf::Font font;
	sf::Text menuItems[5];
	sf::Sprite car;
};

