#pragma once
#include "Engine.h"

/*!
* \brief Struktura zawieraj¹ca klawisze do poruszania siê oraz index gracza
*/
struct Controlls {
	int playerIndex;
	sf::Keyboard::Key forward;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key backward;
};


/*!
* \brief  Struktura zawieraj¹ca numery gracza, samochodu, oraz k¹t i szybkosc uzywane do poruszania sie samochodu
*/
struct PlayersSett {
	int numberOfPlayer;
	int carNumber;
	sf::Texture car;
	float angle;
	float speed;
	Controlls controlls;
};

