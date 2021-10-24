#include "GameSettings.h"
#include <iostream>

GameSettings::GameSettings(int width, int height, bool& gameSett) {
	gameSet = &gameSett;
	cout << "bool: " << gameSet << endl;
	if (!font.loadFromFile("upheavtt.ttf")) {
		//handle error font
	}
	numberOfPlayers = 2;
	itemIndex = 0;

	menuItems[0].setString("ilosc graczy: " + to_string(numberOfPlayers));
	menuItems[0].setCharacterSize(40);
	menuItems[0].setFillColor(sf::Color(255, 0, 0, 255));
	menuItems[0].setFont(font);
	menuItems[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[0].setOutlineThickness(3);
	sf::FloatRect text1 = menuItems[0].getLocalBounds();
	menuItems[0].setOrigin(text1.width / 2, text1.height / 2);
	menuItems[0].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 0.5));

	menuItems[1].setString("Gracz: ");
	menuItems[1].setCharacterSize(40);
	menuItems[1].setFillColor(sf::Color(255, 255, 255, 255));
	menuItems[1].setFont(font);
	menuItems[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItems[1].setOutlineThickness(3);
	sf::FloatRect text2 = menuItems[1].getLocalBounds();
	menuItems[1].setOrigin(text2.width / 2, text2.height / 2);
	menuItems[1].setPosition(sf::Vector2f(width / 2, height / (5 * 1) * 1));

	menuItems[2].setString("Samochod: ");
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
	switch (itemIndex)
	{
	case 4:
		*gameSet = false;
		cout << "bool: " << *gameSet << endl;
		break;
	}
}

void GameSettings::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 5; i++) {
		window.draw(menuItems[i]);
	}
}