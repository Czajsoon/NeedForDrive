#include "Controlls.h"

Controlls::Controlls(int pIndex,int width,int height) {
	playerIndex = pIndex;
	if (!font.loadFromFile("ARCADECLASSIC.ttf")) {
		//handle error
	}
	controllsSet[0].setString("Do przodu ");
	controllsSet[0].setCharacterSize(70);
	controllsSet[0].setFillColor(sf::Color(255, 0, 0, 255));
	controllsSet[0].setPosition(sf::Vector2f(0, height / (CONTROLLS_SET * 1) * 0.5));
	controllsSet[0].setFont(font);
	controllsSet[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllsSet[0].setOutlineThickness(3);
}