#pragma once
#include "Engine.h"
#define CONTROLLS_SET 5


class Controlls {
public:
	Controlls(int pIndex, int width, int height);
	~Controlls();
private:
	int playerIndex;
	sf::Font font;
	sf::Text title;
	sf::Text controllsSet [CONTROLLS_SET];
};