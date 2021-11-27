#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer() {
}

PrimitiveRenderer::~PrimitiveRenderer() {
}

void PrimitiveRenderer::drawSpectators(sf::RenderWindow& window) {
	sf::Vertex line[2];
	line[0].position = sf::Vector2f(window.getSize().x * 0.01f + 50, 0);
	line[0].color = sf::Color::Red;
	line[1].position = sf::Vector2f(window.getSize().x * 0.01f + 50, window.getSize().y);
	line[1].color = sf::Color::Red;
	window.draw(line, 2, sf::Lines);
	for (int i = 0; i < 5; i++) {
		sf::CircleShape shape(20);
		shape.setFillColor(sf::Color(0, 0, 0));
		shape.setPosition(window.getSize().x*0.01f , window.getSize().y *0.03f + 150 * i);
		window.draw(shape);
	}
}