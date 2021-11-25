#pragma once
#include "Engine.h"
#include "Controlls.h"

struct Car {
	sf::Texture car;
};

struct Map {
	sf::Texture map;
};


struct MapSet {
	int mapNumber;
	sf::Sprite playersMap;
};

class GameSettings {
public:
	GameSettings(int width, int height, bool& gameSett,bool& gameS,bool& mainMenu,sf::Texture& gameMap,PlayersSett* playersSett,int& pAmount);
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
	int currentMap;
	int* playersAmount;
	bool* game;
	bool* gameSet;
	bool* menu;
	sf::Texture* finalMap;
	Car cars[3];
	Map maps[3];
	sf::Sprite playersCar;
	PlayersSett* playerSet[3];
	MapSet mapSet[3];
	int numberOfPlayers;
	sf::Font font;
	sf::Text menuItems[6];
	sf::Sprite car;
	sf::Sprite map;
};