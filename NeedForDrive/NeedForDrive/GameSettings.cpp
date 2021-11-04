#include "GameSettings.h"
#include <iostream>

GameSettings::GameSettings(int width, int height, bool& gameSett) {
	this->width = width;
	this->height = height;
	cars[0].playersCar.loadFromFile("cars/1.png");
	cars[1].playersCar.loadFromFile("cars/2.png");
	cars[2].playersCar.loadFromFile("cars/3.png");
	currentPlayer = 0;
	gameSet = &gameSett;
	if (!font.loadFromFile("upheavtt.ttf")) {
		//handle error font
	}
	numberOfPlayers = 2;
	itemIndex = 0;
	for (int i = 0; i < 3; i++) {
		playerSet[i].numberOfPlayer = i + 1;
		playerSet[i].carNumber = 0;
		playerSet[i].playersCar.setTexture(cars[0].playersCar);
		playerSet[i].playersCar.setScale(sf::Vector2f(0.5, 0.5));
		playerSet[i].playersCar.setOrigin(playerSet[i].playersCar.getLocalBounds().width / 2, playerSet[i].playersCar.getLocalBounds().height / 2);
		playerSet[i].playersCar.setPosition(100, this->height / 2);
	}

	menuItems[0].setString("ilosc graczy: " + to_string(numberOfPlayers));
	menuItems[0].setCharacterSize(40);
	menuItems[0].setFillColor(sf::Color(255, 0, 0, 255));
	menuItems[0].setFont(font);
	menuItems[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[0].setOutlineThickness(3);
	sf::FloatRect text1 = menuItems[0].getLocalBounds();
	menuItems[0].setOrigin(text1.width / 2, text1.height / 2);
	menuItems[0].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 0.5));

	menuItems[1].setString("Gracz: 1");
	menuItems[1].setCharacterSize(40);
	menuItems[1].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[1].setFont(font);
	menuItems[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[1].setOutlineThickness(3);
	sf::FloatRect text2 = menuItems[1].getLocalBounds();
	menuItems[1].setOrigin(text2.width / 2, text2.height / 2);
	menuItems[1].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 1));

	menuItems[2].setString("< Samochod >");
	menuItems[2].setCharacterSize(40);
	menuItems[2].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[2].setFont(font);
	menuItems[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[2].setOutlineThickness(3);
	sf::FloatRect text3 = menuItems[2].getLocalBounds();
	menuItems[2].setOrigin(text3.width / 2, text3.height / 2);
	menuItems[2].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 1.5));

	menuItems[3].setString("Mapa: ");
	menuItems[3].setCharacterSize(40);
	menuItems[3].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[3].setFont(font);
	menuItems[3].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[3].setOutlineThickness(3);
	sf::FloatRect text4 = menuItems[3].getLocalBounds();
	menuItems[3].setOrigin(text4.width / 2, text4.height / 2);
	menuItems[3].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 2));

	menuItems[4].setString("Powrot do menu");
	menuItems[4].setCharacterSize(40);
	menuItems[4].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[4].setFont(font);
	menuItems[4].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[4].setOutlineThickness(3);
	sf::FloatRect text5 = menuItems[4].getLocalBounds();
	menuItems[4].setOrigin(text5.width / 2, text5.height / 2);
	menuItems[4].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 2.5));
}

GameSettings::~GameSettings() {

}

void GameSettings::moveUP(){
	if (itemIndex - 1 >= 0) {
		menuItems[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		itemIndex--;
		menuItems[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}

void GameSettings::moveDOWN() {
	if (itemIndex + 1 < 5) {
		menuItems[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		itemIndex++;
		menuItems[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}

void GameSettings::performAction() {
	switch (itemIndex){
	case 0:
		numberOfPlayers++;
		if (numberOfPlayers > 3) numberOfPlayers = 2;
		menuItems[0].setString("ilosc graczy: " + to_string(numberOfPlayers));
		break;
	case 1:
		
		break;
	case 2:
		playerSet[currentPlayer].carNumber++;
		if (playerSet[currentPlayer].carNumber > 2) playerSet[currentPlayer].carNumber = 0;
		playerSet[currentPlayer].playersCar.setTexture(cars[playerSet[currentPlayer].carNumber].playersCar);
		break;
	case 4:
		*gameSet = false;
		break;
	}
}

void GameSettings::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 5; i++) window.draw(menuItems[i]);
	
	window.draw(playerSet[currentPlayer].playersCar);
}