#pragma once
#include "Engine.h"
#include "Controlls.h"

class Game {
public:
	Game(int width, int height, bool& game, bool& mainMenu,PlayersSett* playerSett, sf::Texture& map, int& pAmount);
	~Game();
	void draw(sf::RenderWindow& window);
	void updatePosition();
private:
	sf::Sprite gameMapBackground;
	int* playersAmount;
	bool* workingGame;
	bool* menu;
	bool flagMap;
	PlayersSett* playerSet[3];
	sf::Texture* gameMap;
	sf::Image image;
	sf::Sprite cars[3];
	sf::Texture carsTextures[3];
	float speed[3], angle[3];
	float maxSpeed[3];
	float acc = 0.2f, dec = 0.3f;
	float turnSpeed = 0.08f;
	float x[3],y[3];
};