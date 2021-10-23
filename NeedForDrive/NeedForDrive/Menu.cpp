#include "Menu.h"
#include <cmath>
#include <iostream>

Menu::Menu(int width, int height) {
	settingsResolution = 0;
	resolutions[0].width = 1280;
	resolutions[0].height = 720;
	resolutions[1].width = 1920;
	resolutions[1].height = 1080;
	resolutions[2].width = 1440;
	resolutions[2].height = 900;
	itemIndex = 0;
	settingsIndex = 0;
	settings = false;
	fullscreen = false;
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
	menuItem[0].setPosition(sf::Vector2f(width/2, height / (MAX_MENU_ITEMS * 1) * 0.5));


	menuItem[1].setString("Ustawienia");
	menuItem[1].setFillColor(sf::Color(255, 255, 255, 255));
	menuItem[1].setCharacterSize(70);
	menuItem[1].setFont(font);
	menuItem[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItem[1].setOutlineThickness(3);
	sf::FloatRect text2 = menuItem[1].getLocalBounds();
	menuItem[1].setOrigin(text2.width / 2, text2.height / 2);
	menuItem[1].setPosition(sf::Vector2f(width/2, height / (MAX_MENU_ITEMS * 1) * 1));

	menuItem[2].setString("Wyjdz");
	menuItem[2].setFillColor(sf::Color(255, 255, 255, 255));
	menuItem[2].setCharacterSize(70);
	menuItem[2].setFont(font);
	menuItem[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	menuItem[2].setOutlineThickness(3);
	sf::FloatRect text3 = menuItem[2].getLocalBounds();
	menuItem[2].setOrigin(text3.width / 2, text3.height / 2);
	menuItem[2].setPosition(sf::Vector2f(width/2, height / (MAX_MENU_ITEMS * 1) * 1.5));

	settingsItem[0].setString("Rozdzielczosc - " + std::to_string(width) + " x " + std::to_string(height) +" +");
	settingsItem[0].setFillColor(sf::Color(255, 0, 0, 255));
	settingsItem[0].setCharacterSize(30);
	settingsItem[0].setFont(font);
	settingsItem[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	settingsItem[0].setOutlineThickness(3);
	sf::FloatRect stext1 = settingsItem[0].getLocalBounds();
	settingsItem[0].setOrigin(stext1.width / 2, stext1.height / 2);
	settingsItem[0].setPosition(sf::Vector2f(width/2, height / (MAX_SETTINGS_ITEMS * 1) * 0.5));

	settingsItem[1].setString("Sterowanie");
	settingsItem[1].setFillColor(sf::Color(255, 255, 255, 255));
	settingsItem[1].setCharacterSize(30);
	settingsItem[1].setFont(font);
	settingsItem[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	settingsItem[1].setOutlineThickness(3);
	sf::FloatRect stext2 = settingsItem[1].getLocalBounds();
	settingsItem[1].setOrigin(stext2.width / 2, stext2.height / 2);
	settingsItem[1].setPosition(sf::Vector2f(width/2, height / (MAX_SETTINGS_ITEMS * 1) * 1));

	settingsItem[2].setString("Powrot do menu");
	settingsItem[2].setFillColor(sf::Color(255, 255, 255, 255));
	settingsItem[2].setCharacterSize(30);
	settingsItem[2].setFont(font);
	settingsItem[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	settingsItem[2].setOutlineThickness(3);
	sf::FloatRect stext3 = settingsItem[2].getLocalBounds();
	settingsItem[2].setOrigin(stext3.width / 2, stext3.height / 2);
	settingsItem[2].setPosition(sf::Vector2f(width/2, height / (MAX_SETTINGS_ITEMS * 1) * 1.5));
}

Menu::~Menu() {

}

void Menu::drawMenu(sf::RenderWindow& window) {
	window.draw(background);
	if (!settings) {
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			window.draw(menuItem[i]);
		}
	}
	else {
		for (int i = 0; i < MAX_SETTINGS_ITEMS; i++) {
			window.draw(settingsItem[i]);
		}
	}
}

void Menu::moveUP() {
	if (!settings) {
		if (itemIndex - 1 >= 0) {
			sound.play();
			menuItem[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
			itemIndex--;
			menuItem[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
		}
	}
	else {
		if (settingsIndex - 1 >= 0) {
			sound.play();
			settingsItem[settingsIndex].setFillColor(sf::Color(255, 255, 255, 255));
			settingsIndex--;
			settingsItem[settingsIndex].setFillColor(sf::Color(255, 0, 0, 255));
		}
	}
}

void Menu::moveDOWN() {
	if (!settings) {
		if (itemIndex + 1 < MAX_MENU_ITEMS) {
			sound.play();
			menuItem[itemIndex].setFillColor(sf::Color(255, 255, 255, 255));
			itemIndex++;
			menuItem[itemIndex].setFillColor(sf::Color(255, 0, 0, 255));
		}
	}
	else {
		if (settingsIndex + 1 < MAX_SETTINGS_ITEMS) {
			sound.play();
			settingsItem[settingsIndex].setFillColor(sf::Color(255, 255, 255, 255));
			settingsIndex++;
			settingsItem[settingsIndex].setFillColor(sf::Color(255, 0, 0, 255));
		}
	}
	
}

void Menu::performAction(sf::RenderWindow& window) {
	if (!settings) {
		switch (itemIndex) {
		case 0:
			sound.play();
			break;
		case 1:
			sound.play();
			settings = true;
			break;
		case 2:
			window.close();
			break;
		}
	}
	else {
		switch (settingsIndex) {
		case 0://resolution 
			settingsResolution++;
			sound.play();
			if (settingsResolution >= MAX_RESOLUTION_ITEMS) settingsResolution = 0;
			settingsItem[0].setString("Rozdzielczosc - " + std::to_string(resolutions[settingsResolution].width) + " x " + std::to_string(resolutions[settingsResolution].height) + " +");
			window.setSize(sf::Vector2u(resolutions[settingsResolution].width, resolutions[settingsResolution].height));
			break;
		case 1://controlls
			sound.play();
			break;
		case 2://back to main menu
			sound.play();
			settings = false;
			break;
		}
	}
}