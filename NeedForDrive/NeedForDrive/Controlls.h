#pragma once
#include "Engine.h"
#define CONTROLLS_SET 5


class Controlls {
public:
	Controlls();
	Controlls(int pIndex, int width, int height);
	~Controlls();
	void draw(sf::RenderWindow& window);
	sf::Keyboard::Key forward;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key backward;
private:
	int playerIndex;
	std::string fromKtoS(const sf::Keyboard::Key& k);
	sf::Font font;
	sf::Text title;
	sf::Text controllsSet [CONTROLLS_SET];
};