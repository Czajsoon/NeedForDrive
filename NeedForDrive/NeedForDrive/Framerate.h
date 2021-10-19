#pragma once
#include "Engine.h"

class FrameRate {
public:
	FrameRate(float time);
	~FrameRate();
	void draw(sf::RenderWindow& window);
private:
	sf::Text frames;
	sf::Font font;

};