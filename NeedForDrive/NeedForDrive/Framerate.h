#pragma once
#include "Engine.h"

/*!
* \brief  Klasa używana do zarządzania częstotliwością wyświetlania obrazu
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
