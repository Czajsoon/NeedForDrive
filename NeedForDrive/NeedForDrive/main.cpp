#include <SFML/graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "title");
	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;

}