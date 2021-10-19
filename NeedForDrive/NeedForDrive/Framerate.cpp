#include "Framerate.h"
#include <string.h>
#include <iostream>

FrameRate::FrameRate(float time) {
	font.loadFromFile("arial.ttf");
	//std::cout << std::to_string(time) << std::endl;
	frames.setString("123");
	frames.setFillColor(sf::Color(255, 255, 255, 255));
	frames.setPosition(sf::Vector2f(0, 0));

}


FrameRate::~FrameRate() {

}

void FrameRate::draw(sf::RenderWindow& window) {
	window.draw(frames);
}