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
		carsTextures[i].loadFromFile("cars/" + to_string(i + 1) + ".png");
		playerSet[i] = &playerSett[i];
	}
	for (int i = 0; i < *playersAmount; i++) {
		playerSet[i]->car = carsTextures[playerSet[i]->carNumber];
		cars[i].setTexture(playerSet[i]->car);
		cars[i].setScale(sf::Vector2f(0.15, 0.15));
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

	if (sf::Keyboard::isKeyPressed(playerSet[0]->controlls.forward)) {
		cars[0].move(sf::Vector2f(.0f, -3.0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[0]->controlls.backward)) {
		cars[0].move(sf::Vector2f(.0f, 3.0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[0]->controlls.left)) {
		cars[0].move(sf::Vector2f(-3.0f, .0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[0]->controlls.right)) {
		cars[0].move(sf::Vector2f(3.0f, .0f));
	}
	
	if (sf::Keyboard::isKeyPressed(playerSet[1]->controlls.forward)) {
		cars[1].move(sf::Vector2f(.0f, -3.0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[1]->controlls.backward)) {
		cars[1].move(sf::Vector2f(.0f, 3.0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[1]->controlls.left)) {
		cars[1].move(sf::Vector2f(-3.0f, .0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[1]->controlls.right)) {
		cars[1].move(sf::Vector2f(3.0f, .0f));
	}

	if (sf::Keyboard::isKeyPressed(playerSet[2]->controlls.forward)) {
		cars[2].move(sf::Vector2f(.0f, -3.0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[2]->controlls.backward)) {
		cars[2].move(sf::Vector2f(.0f, 3.0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[2]->controlls.left)) {
		cars[2].move(sf::Vector2f(-3.0f, .0f));
	}
	if (sf::Keyboard::isKeyPressed(playerSet[2]->controlls.right)) {
		cars[2].move(sf::Vector2f(3.0f, .0f));
	}

}

