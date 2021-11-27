#pragma once
#include "Engine.h"

/*!
* \brief  Klasa u�ywana do zarz�dzania cz�stotliwo�ci� wy�wietlania obrazu
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
