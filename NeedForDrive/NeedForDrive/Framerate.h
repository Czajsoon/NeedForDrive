#pragma once
#include "Engine.h"

/*!
* \brief  Klasa u¿ywana do zarz¹dzania czêstotliwoœci¹ wyœwietlania obrazu
*/

class FrameRate {
public:
	FrameRate(float time);
	~FrameRate();
	void draw(sf::RenderWindow& window);
private:
	sf::Text frames;
	sf::Font font;

};
