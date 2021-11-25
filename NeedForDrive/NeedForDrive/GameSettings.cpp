#include "GameSettings.h"
#include <iostream>

GameSettings::GameSettings(int width, int height, bool& gameSett, bool& gameS,bool& mainMenu, sf::Texture& gameMap, PlayersSett* playersSett,int& pAmount) {
	this->width = width;
	this->height = height;
	cars[0].car.loadFromFile("cars/1.png");
	cars[1].car.loadFromFile("cars/2.png");
	cars[2].car.loadFromFile("cars/3.png");
	maps[0].map.loadFromFile("maps/1x.png");
	maps[1].map.loadFromFile("maps/2x.png");
	maps[2].map.loadFromFile("maps/3x.png");
	finalMap = &gameMap;
	*finalMap = maps[0].map;
	menu = &mainMenu;
	currentPlayer = 0;
	currentMap = 0;
	playersAmount = &pAmount;
	game = &gameS;
	gameSet = &gameSett;
	if (!font.loadFromFile("upheavtt.ttf")) {
		//handle error font
	}
	numberOfPlayers = 2;
	*playersAmount = 2;
	itemIndex = 0;
	playersCar.setTexture(cars[0].car);
	playersCar.setScale(sf::Vector2f(0.5, 0.5));
	playersCar.setOrigin(playersCar.getLocalBounds().width / 2, playersCar.getLocalBounds().height / 2);
	playersCar.setPosition(100, this->height / 2);

	for (int i = 0; i < 3; i++) {
		playerSet[i] = &playersSett[i];
		playerSet[i]->carNumber = 0;
		playerSet[i]->numberOfPlayer = i + 1;
	}

	for (int i = 0; i < 3; i++) {
		mapSet[i].mapNumber = 0;
		mapSet[i].playersMap.setTexture(maps[0].map);
		mapSet[i].playersMap.setScale(sf::Vector2f(0.3, 0.3));
		mapSet[i].playersMap.setOrigin(mapSet[i].playersMap.getLocalBounds().width / 2, mapSet[i].playersMap.getLocalBounds().height / 2);
		mapSet[i].playersMap.setPosition(1050, this->height / 2);
	}

	menuItems[0].setString("Graj");
	menuItems[0].setCharacterSize(40);
	menuItems[0].setFillColor(sf::Color(255, 0, 0, 255));
	menuItems[0].setFont(font);
	menuItems[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[0].setOutlineThickness(3);
	sf::FloatRect text0 = menuItems[0].getLocalBounds();
	menuItems[0].setOrigin(text0.width / 2, text0.height / 2);
	menuItems[0].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 0.5));

	menuItems[1].setString("Ilosc graczy: " + to_string(numberOfPlayers));
	menuItems[1].setCharacterSize(40);
	menuItems[1].setFillColor(sf::Color(255, 255, 255));
	menuItems[1].setFont(font);
	menuItems[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[1].setOutlineThickness(3);
	sf::FloatRect text1 = menuItems[1].getLocalBounds();
	menuItems[1].setOrigin(text1.width / 2, text1.height / 2);
	menuItems[1].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 1));

	menuItems[2].setString("Gracz: " + to_string(currentPlayer + 1));
	menuItems[2].setCharacterSize(40);
	menuItems[2].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[2].setFont(font);
	menuItems[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[2].setOutlineThickness(3);
	sf::FloatRect text2 = menuItems[2].getLocalBounds();
	menuItems[2].setOrigin(text2.width / 2, text2.height / 2);
	menuItems[2].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 1.5));

	menuItems[3].setString("< Samochod >");
	menuItems[3].setCharacterSize(40);
	menuItems[3].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[3].setFont(font);
	menuItems[3].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[3].setOutlineThickness(3);
	sf::FloatRect text3 = menuItems[3].getLocalBounds();
	menuItems[3].setOrigin(text3.width / 2, text3.height / 2);
	menuItems[3].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 2));

	menuItems[4].setString("< Mapa >");
	menuItems[4].setCharacterSize(40);
	menuItems[4].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[4].setFont(font);
	menuItems[4].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[4].setOutlineThickness(3);
	sf::FloatRect text4 = menuItems[4].getLocalBounds();
	menuItems[4].setOrigin(text4.width / 2, text4.height / 2);
	menuItems[4].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 2.5));

	menuItems[5].setString("Powrot do menu");
	menuItems[5].setCharacterSize(40);
	menuItems[5].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[5].setFont(font);
	menuItems[5].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[5].setOutlineThickness(3);
	sf::FloatRect text5 = menuItems[5].getLocalBounds();
	menuItems[5].setOrigin(text5.width / 2, text5.height / 2);
	menuItems[5].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 3));
}

GameSettings::~GameSettings() {

}

void GameSettings::moveUP() {
	if (itemIndex - 1 >= 0) {
		menuItems[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		itemIndex--;
		menuItems[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}

void GameSettings::moveDOWN() {
	if (itemIndex + 1 < 6) {
		menuItems[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		itemIndex++;
		menuItems[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}

void GameSettings::performAction() {
	switch (itemIndex) {
	case 0: 
		//start gry!
		*gameSet = false;
		*game = true;
		*menu = false;
		break;
	case 1:
		//zmiana liczby graczy
		numberOfPlayers++;
		if (numberOfPlayers > 3) numberOfPlayers = 2;
		menuItems[1].setString("Ilosc graczy: " + to_string(numberOfPlayers));
		*playersAmount = numberOfPlayers;
		break;
	case 2:
		//zmiana gracza
		currentPlayer++;
		if (currentPlayer >= numberOfPlayers) currentPlayer = 0;
		menuItems[2].setString("Gracz: " + to_string(currentPlayer + 1));
		playersCar.setTexture(cars[playerSet[currentPlayer]->carNumber].car);
		break;
	case 3:
		//wybor samochodu
		playerSet[currentPlayer]->carNumber++;
		if (playerSet[currentPlayer]->carNumber > 2) playerSet[currentPlayer]->carNumber = 0;
		playerSet[currentPlayer]->car = cars[playerSet[currentPlayer]->carNumber].car;
		playersCar.setTexture(playerSet[currentPlayer]->car);
		//playersCar.setTexture(cars[playerSet[currentPlayer]->carNumber].car);
		
		break;
	case 4:
		//wybor mapy
		mapSet[currentMap].mapNumber++;
		if (mapSet[currentMap].mapNumber > 2) mapSet[currentMap].mapNumber = 0;
		mapSet[currentMap].playersMap.setTexture(maps[mapSet[currentMap].mapNumber].map);
		*finalMap = maps[mapSet[currentMap].mapNumber].map;
		break;
	case 5:
		//powrot do menu
		*menu = true;
		*gameSet = false;
		break;
	}
}

void GameSettings::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 6; i++) window.draw(menuItems[i]);
	
	window.draw(playersCar);
	window.draw(mapSet[currentMap].playersMap);
}