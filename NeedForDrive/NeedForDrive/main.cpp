#include "Engine.h"
#include "Menu.h"
#include "Framerate.h"
#include <iostream>

int main() {
	Engine engine;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "NeedForDrive"); 
	window.setFramerateLimit(60);
	
	Menu menu(window.getSize().x, window.getSize().y);
	sf::Event event;
	sf::Clock clock;
	
	while (window.isOpen()) { 
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyReleased: {
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.moveUP();
					break;
				case sf::Keyboard::Down:
					menu.moveDOWN();
					break;
				case sf::Keyboard::Enter:
					menu.performAction(window);
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			}
			case sf::Event::Closed: {
				window.close();
				break;
			}	
			}
		}
		window.clear();
		menu.drawMenu(window);
		window.display();
		clock.restart();
	}
	return 0;
}