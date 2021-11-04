#include "Menu.h"
#include "KeyboardToString.h"
#include <string.h>

Menu::Menu(int width, int height) {
	gameSet = false;
	gameSettings = new GameSettings(width,height,gameSet);
	controllIndex = 0;
	playerIndex = 0;
	settingsResolution = 0;
	if (!mainThermeMusicBuffer.loadFromFile("mainMusic.wav")) {
		//handle error
	}
	mainThermeMusic.setBuffer(mainThermeMusicBuffer);
	mainThermeMusic.setVolume(20);
	mainThermeMusic.play();
	controlls[0].playerIndex = 1;
	controlls[0].forward = sf::Keyboard::Key::Up;
	controlls[0].backward = sf::Keyboard::Key::Down;
	controlls[0].left = sf::Keyboard::Key::Left;
	controlls[0].right = sf::Keyboard::Key::Right;
	controlls[1].playerIndex = 2;
	controlls[1].forward = sf::Keyboard::Key::W;
	controlls[1].backward = sf::Keyboard::Key::S;
	controlls[1].left = sf::Keyboard::Key::A;
	controlls[1].right = sf::Keyboard::Key::D;
	controlls[2].playerIndex = 3;
	controlls[2].forward = sf::Keyboard::Key::Y;
	controlls[2].backward = sf::Keyboard::Key::H;
	controlls[2].left = sf::Keyboard::Key::G;
	controlls[2].right = sf::Keyboard::Key::J;
	resolutions[0].width = 1280;
	resolutions[0].height = 720;
	resolutions[1].width = 1920;
	resolutions[1].height = 1080;
	resolutions[2].width = 1440;
	resolutions[2].height = 900;
	itemIndex = 0;
	settingsIndex = 0;
	settings = false;
	control = false;
	if (!font.loadFromFile("upheavtt.ttf")) {
		//handle error font
	}
	if (!backgroundImage.loadFromFile("background.png")) {
		//handle error background
	}
	if (!soundBuffer.loadFromFile("menuSound.wav")) {
		//handle error audio
	}
	sound.setBuffer(soundBuffer);
	background.setTexture(backgroundImage);
	background.setScale(sf::Vector2f(0.35, 0.35));

	menuItem[0].setString("Zagraj");
	menuItem[0].setCharacterSize(70);
	menuItem[0].setFillColor(sf::Color(255, 0, 0, 255));
	menuItem[0].setFont(font);
	menuItem[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItem[0].setOutlineThickness(3);
	sf::FloatRect text1 = menuItem[0].getLocalBounds();
	menuItem[0].setOrigin(text1.width / 2, text1.height / 2);
	menuItem[0].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS * 1) * 0.5));

	menuItem[1].setString("Ustawienia");
	menuItem[1].setFillColor(sf::Color(255, 255, 255, 255));
	menuItem[1].setCharacterSize(70);
	menuItem[1].setFont(font);
	menuItem[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItem[1].setOutlineThickness(3);
	sf::FloatRect text2 = menuItem[1].getLocalBounds();
	menuItem[1].setOrigin(text2.width / 2, text2.height / 2);
	menuItem[1].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS * 1) * 1));

	menuItem[2].setString("Wyjdz");
	menuItem[2].setFillColor(sf::Color(255, 255, 255, 255));
	menuItem[2].setCharacterSize(70);
	menuItem[2].setFont(font);
	menuItem[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItem[2].setOutlineThickness(3);
	sf::FloatRect text3 = menuItem[2].getLocalBounds();
	menuItem[2].setOrigin(text3.width / 2, text3.height / 2);
	menuItem[2].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS * 1) * 1.5));

	settingsItem[0].setString("Rozdzielczosc - " + std::to_string(width) + " x " + std::to_string(height) + " +");
	settingsItem[0].setFillColor(sf::Color(255, 0, 0, 255));
	settingsItem[0].setCharacterSize(60);
	settingsItem[0].setFont(font);
	settingsItem[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	settingsItem[0].setOutlineThickness(3);
	sf::FloatRect stext1 = settingsItem[0].getLocalBounds();
	settingsItem[0].setOrigin(stext1.width / 2, stext1.height / 2);
	settingsItem[0].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 0.5));

	settingsItem[1].setString("Sterowanie");
	settingsItem[1].setFillColor(sf::Color(255, 255, 255, 255));
	settingsItem[1].setCharacterSize(60);
	settingsItem[1].setFont(font);
	settingsItem[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	settingsItem[1].setOutlineThickness(3);
	sf::FloatRect stext2 = settingsItem[1].getLocalBounds();
	settingsItem[1].setOrigin(stext2.width / 2, stext2.height / 2);
	settingsItem[1].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 1));

	settingsItem[2].setString("Powrot do menu");
	settingsItem[2].setFillColor(sf::Color(255, 255, 255, 255));
	settingsItem[2].setCharacterSize(60);
	settingsItem[2].setFont(font);
	settingsItem[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	settingsItem[2].setOutlineThickness(3);
	sf::FloatRect stext3 = settingsItem[2].getLocalBounds();
	settingsItem[2].setOrigin(stext3.width / 2, stext3.height / 2);
	settingsItem[2].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 1.5));

	controllItems[0].setString("Gracz: " + std::to_string(controlls[0].playerIndex));
	controllItems[0].setFillColor(sf::Color(255, 0, 0, 255));
	controllItems[0].setCharacterSize(40);
	controllItems[0].setFont(font);
	controllItems[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllItems[0].setOutlineThickness(3);
	sf::FloatRect ctext1 = controllItems[0].getLocalBounds();
	controllItems[0].setOrigin(ctext1.width / 2, ctext1.height / 2);
	controllItems[0].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 0.25));

	controllItems[1].setString("Przyspieszenie: " + fromKtoS(controlls[0].forward));
	controllItems[1].setFillColor(sf::Color(255, 255, 255, 255));
	controllItems[1].setCharacterSize(40);
	controllItems[1].setFont(font);
	controllItems[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllItems[1].setOutlineThickness(3);
	sf::FloatRect ctext2 = controllItems[1].getLocalBounds();
	controllItems[1].setOrigin(ctext2.width / 2, ctext2.height / 2);
	controllItems[1].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 0.5));

	controllItems[2].setString("Hamulec: " + fromKtoS(controlls[0].backward));
	controllItems[2].setFillColor(sf::Color(255, 255, 255, 255));
	controllItems[2].setCharacterSize(40);
	controllItems[2].setFont(font);
	controllItems[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllItems[2].setOutlineThickness(3);
	sf::FloatRect ctext3 = controllItems[2].getLocalBounds();
	controllItems[2].setOrigin(ctext3.width / 2, ctext3.height / 2);
	controllItems[2].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 0.75));

	controllItems[3].setString("Skret w lewo: " + fromKtoS(controlls[0].left));
	controllItems[3].setFillColor(sf::Color(255, 255, 255, 255));
	controllItems[3].setCharacterSize(40);
	controllItems[3].setFont(font);
	controllItems[3].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllItems[3].setOutlineThickness(3);
	sf::FloatRect ctext4 = controllItems[3].getLocalBounds();
	controllItems[3].setOrigin(ctext4.width / 2, ctext4.height / 2);
	controllItems[3].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 1));

	controllItems[4].setString("Skret w prawo: " + fromKtoS(controlls[0].right));
	controllItems[4].setFillColor(sf::Color(255, 255, 255, 255));
	controllItems[4].setCharacterSize(40);
	controllItems[4].setFont(font);
	controllItems[4].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllItems[4].setOutlineThickness(3);
	sf::FloatRect ctext5 = controllItems[4].getLocalBounds();
	controllItems[4].setOrigin(ctext5.width / 2, ctext5.height / 2);
	controllItems[4].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 1.25));

	controllItems[5].setString("Powrot do ustawien");
	controllItems[5].setFillColor(sf::Color(255, 255, 255, 255));
	controllItems[5].setCharacterSize(40);
	controllItems[5].setFont(font);
	controllItems[5].setOutlineColor(sf::Color(0, 0, 0, 255));
	controllItems[5].setOutlineThickness(3);
	sf::FloatRect ctext6 = controllItems[5].getLocalBounds();
	controllItems[5].setOrigin(ctext6.width / 2, ctext6.height / 2);
	controllItems[5].setPosition(sf::Vector2f(width / 2, height / (MAX_SETTINGS_ITEMS * 1) * 1.5));
}

Menu::~Menu() {
	if (gameSettings != NULL)
		delete gameSettings;
}
