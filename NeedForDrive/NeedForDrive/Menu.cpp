#include "Menu.h"
#include "Engine.h"

Menu::Menu(float width, float height) {
	itemIndex = 0;
	if (!font.loadFromFile("arial.ttf")) {
		//handle error
	}
	menuItem[0].setString("Zagraj");
	menuItem[0].setFillColor(sf::Color(255, 0, 0, 255));
	menuItem[0].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS * 1) * 0.5));
	menuItem[0].setFont(font);

	menuItem[1].setString("Ustawienia");
	menuItem[1].setFillColor(sf::Color(255, 255, 255, 255));
	menuItem[1].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS * 1) * 1));
	menuItem[1].setFont(font);

	menuItem[2].setString("Wyjdz");
	menuItem[2].setFillColor(sf::Color(255, 255, 255, 255));
	menuItem[2].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS * 1) * 1.5));
	menuItem[2].setFont(font);
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < MAX_MENU_ITEMS; i++) {
		window.draw(menuItem[i]);
	}
}

void Menu::moveUP() {
	if (itemIndex - 1 >= 0) {
		menuItem[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		itemIndex--;
		menuItem[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}

void Menu::moveDOWN() {
	if (itemIndex + 1 < MAX_MENU_ITEMS) {
		menuItem[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		itemIndex++;
		menuItem[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}