#include "Game.h"
#include "iostream"
#include "string.h"
#include "KeyboardToString.h"

Game::Game(int width, int height, bool& game, bool& mainMenu, PlayersSett* playerSett, sf::Texture& map,int& pAmount) {
	workingGame = &game;
	gameMap = &map;
	playersAmount = &pAmount;
	menu = &mainMenu;
	for (int i = 0; i < 3; i++) {
		//cars[i].setPosition(sf::Vector2f(50 * i, 0));
		carsTextures[i].loadFromFile("cars/" + to_string(i + 1) + ".png");
		x[i] = 50 *i;
		y[i] = 0;
		speed[i] = 0;
		angle[i] = 0;
		maxSpeed[i] = 6.0f;
		playerSet[i] = &playerSett[i];
		playerSet[i]->car = carsTextures[playerSet[i]->carNumber];
		cars[i].setTexture(playerSet[i]->car);
		cars[i].setScale(sf::Vector2f(0.15f, 0.15f));
		cars[i].setOrigin(22,22);
	}
	gameMapBackground.setTexture(*gameMap);
}

Game::~Game() {

}

void Game::draw(sf::RenderWindow& window) {
	window.draw(gameMapBackground);
	for (int i = 0; i < *playersAmount; i++) {
		window.draw(cars[i]);
	}
}

void Game::updatePosition() {
	for (int i = 0; i < *playersAmount; i++) {
		if (sf::Keyboard::isKeyPressed(playerSet[i]->controlls.forward) && speed[i] < maxSpeed[i]) {
			if (speed[i] < 0) speed[i] += dec;
			else speed[i] += acc;
		}
		if (sf::Keyboard::isKeyPressed(playerSet[i]->controlls.backward) && speed[i] > -maxSpeed[i]) {
			if (speed[i] > 0) speed[i] -= dec;
			else speed[i] -= acc;

		}
		if (!sf::Keyboard::isKeyPressed(playerSet[i]->controlls.forward) && !sf::Keyboard::isKeyPressed(playerSet[i]->controlls.backward)) {
			if (speed[i] - dec > 0) speed[i] -= dec;
			else if (speed[i] + dec < 0) speed[i] += dec;
			else speed[i] = 0;
		}
		if (sf::Keyboard::isKeyPressed(playerSet[i]->controlls.right) && speed[i] != 0) angle[i] += turnSpeed * playerSet[i]->speed / maxSpeed[i];
		if (sf::Keyboard::isKeyPressed(playerSet[i]->controlls.left) && speed[i] != 0) angle[i] -= turnSpeed * playerSet[i]->speed / maxSpeed[i];
		playerSet[i]->speed = speed[i];
		playerSet[i]->angle = angle[i];
		x[i] += sin(angle[i]) * speed[i];
		y[i] -= cos(angle[i]) * speed[i];
		std::cout << "x gracz: " << i << x[i] << endl;
		std::cout << "y gracz: " << i << y[i] << endl;
		cars[i].setPosition(x[i], y[i]);
		cars[i].setRotation(angle[i] * 180.0f / 3.141593f);
	}
}

