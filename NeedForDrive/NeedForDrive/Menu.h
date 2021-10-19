#pragma once
#include <SFML/Graphics.hpp>
#define MAX_MENU_ITEMS 3

class Menu {
public:
	Menu(float height, float width);
	~Menu();
	void draw(sf::RenderWindow& window);
	void moveUP();
	void moveDOWN();
private:
	int itemIndex;
	sf::Font font;
	sf::Text menuItem[MAX_MENU_ITEMS];
};