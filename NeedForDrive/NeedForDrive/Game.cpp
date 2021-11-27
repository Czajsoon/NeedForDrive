#include "Game.h"
#include "iostream"
#include "string.h"
#include "KeyboardToString.h"
#include "Collision.hpp"

Game::Game(int width, int height, bool& game, bool& mainMenu, PlayersSett* playerSett, sf::Texture& map,int& pAmount) {
	primitive = new PrimitiveRenderer();
	flagMap = true;
	workingGame = &game;
	gameMap = &map;
	playersAmount = &pAmount;
	menu = &mainMenu;
	for (int i = 0; i < 3; i++) {
		carsTextures[i].loadFromFile("cars/" + to_string(i + 1) + ".png");
		if (i == 0) {
			x[i] = 600;
			y[i] = 590;
		}
		if (i == 1) {
			x[i] = 600;
			y[i] = 630;
		}
		if (i == 2) {
			x[i] = 680;
			y[i] = 610;
		}
		speed[i] = 0;
		angle[i] = 180.64;
		maxSpeed[i] = 6.0f;
		playerSet[i] = &playerSett[i];
		playerSet[i]->car = carsTextures[playerSet[i]->carNumber];
		cars[i].setTexture(playerSet[i]->car);
		cars[i].setScale(sf::Vector2f(0.1f, 0.1f));
		cars[i].setOrigin(cars[i].getLocalBounds().height/2 , cars[i].getLocalBounds().width/2);
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
	primitive->drawSpectators(window);
}

void Game::updatePosition() {
	if(flagMap)image = gameMap->copyToImage();
	flagMap = false;

	for (int i = 0; i < *playersAmount; i++) {
		bool grassColission = image.getPixel(x[i], y[i]) == sf::Color(30, 157, 0);
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
		cars[i].setPosition(x[i], y[i]);
		cars[i].setRotation(angle[i] * 180.0f / 3.141593f);
		for (int j = 0; j < *playersAmount; j++) {
			if (playerSet[i]->numberOfPlayer != playerSet[j]->numberOfPlayer) {
				if (Collision::PixelPerfectTest(cars[i], cars[j])) {
					if (speed[i] > 0 && speed[j] > 0) {
						speed[i] *= 0.5f;
						speed[j] *= 1.5f;
					}
					else if (speed[i] > 0 && speed[j] < 0) {
						speed[i] *= 0.4f;
						speed[j] *= -1.1f;
					}
					else if (speed[i] < 0 && speed[j] > 0) {
						speed[i] *= -1.1f;
						speed[j] *= 0.4f;
					}
					else if (speed[i] > 0 && speed[j] == 0) {
						speed[j] = speed[i] * 0.8f;
						speed[i] *= 0.4f;
					}
					else if (speed[i] == 0 && speed[j] > 0) {
						speed[i] = speed[j] * 0.8f;
						speed[j] *= 0.4f;
					}
					else if (speed[i] < 0 && speed[j] < 0) {
						speed[i] *= 0.5f;
						speed[j] *= 1.5f;
					}
				}
			}
		}
		if (grassColission) {
			speed[i] *= -1;
		}
	}
}

