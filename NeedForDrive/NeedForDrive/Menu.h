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
	void performAction(sf::RenderWindow& window);
private:
	int itemIndex;
	sf::Texture backgroundImage;
	sf::Sprite background;
	sf::Font font;
	sf::Text menuItem[MAX_MENU_ITEMS];
};