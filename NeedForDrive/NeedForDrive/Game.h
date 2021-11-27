#pragma once
#include "Engine.h"
#include "Controlls.h"

/*!
* \brief  Klasa u¿ywana do ustawienia g³ównego okna z gr¹
* Klasa przyjmuje parametry: 
* width i height- wymiary okna
* wskaŸniki na zmienne typu bool game i mainMenu- flagi do wyœwietlania gry i menu
* strukturê PlayersSett
* texturê mapy
* wskaŸnik na zmienn¹ typu int- liczba graczy
*/
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