#pragma once
#include "Engine.h"


struct Controlls {
	int playerIndex;
	sf::Keyboard::Key forward;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key backward;
};


struct PlayersSett {
	int numberOfPlayer;
	int carNumber;
	sf::Texture car;
	float angle;
	float speed;
	Controlls controlls;
};