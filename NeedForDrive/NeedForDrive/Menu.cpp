#include "Menu.h"
#include "KeyboardToString.h"
#include <cmath>
#include <iostream>

void Menu::drawMenu(sf::RenderWindow& window) {
	window.draw(background);
	if (!settings) {
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			window.draw(menuItem[i]);
		}
	}
	else if (control) {
		for (int i = 0; i < MAX_CONTROLLS_ITEMS; i++) {
			window.draw(controllItems[i]);
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
	else if (control) {
		if (controllIndex - 1 >= 0) {
			sound.play();
			controllItems[controllIndex].setFillColor(sf::Color(255, 255, 255, 255));
			controllIndex--;
			controllItems[controllIndex].setFillColor(sf::Color(255, 0, 0, 255));
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
	else if (control) {
		if (controllIndex + 1 < MAX_CONTROLLS_ITEMS) {
			sound.play();
			controllItems[controllIndex].setFillColor(sf::Color(255, 255, 255, 255));
			controllIndex++;
			controllItems[controllIndex].setFillColor(sf::Color(255, 0, 0, 255));
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
	else if (control) {
		sf::Event bind;
		switch (controllIndex) {
		case 0:
			sound.play();
			playerIndex++;
			if (playerIndex >= MAX_PLAYERS)
				playerIndex = 0;
			controllItems[0].setString("Gracz: " + std::to_string(controlls[playerIndex].playerIndex));
			controllItems[1].setString("Przyspieszenie: " + fromKtoS(controlls[playerIndex].forward));
			controllItems[2].setString("Hamulec: " + fromKtoS(controlls[playerIndex].backward));
			controllItems[3].setString("Skret w lewo: " + fromKtoS(controlls[playerIndex].left));
			controllItems[4].setString("Skret w prawo: " + fromKtoS(controlls[playerIndex].right));
			break;
		case 1:
			sound.play();
			while (window.waitEvent(bind)) {
				if (bind.KeyReleased) {
					controlls[playerIndex].forward = bind.key.code;
					controllItems[1].setString("Przyspieszenie: " + fromKtoS(controlls[playerIndex].forward));
					break;
				}
			}
			break;
		case 2:
			sound.play();
			while (window.waitEvent(bind)) {
				if (bind.KeyReleased) {
					controlls[playerIndex].backward = bind.key.code;
					controllItems[2].setString("Hamulec: " + fromKtoS(controlls[playerIndex].backward));
					break;
				}
			}
			break;
		case 3:
			sound.play();
			while (window.waitEvent(bind)) {
				if (bind.KeyReleased) {
					controlls[playerIndex].left = bind.key.code;
					controllItems[3].setString("Skret w lewo : " + fromKtoS(controlls[playerIndex].left));
					break;
				}
			}
			break;
		case 4:
			sound.play();
			while (window.waitEvent(bind)) {
				if (bind.KeyReleased) {
					controlls[playerIndex].right = bind.key.code;
					controllItems[3].setString("Skret w prawo : " + fromKtoS(controlls[playerIndex].right));
					break;
				}
			}
			break;
		case 5:
			sound.play();
			control = false;
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
			control = true;
			break;
		case 2://back to main menu
			sound.play();
			settings = false;
			break;
		}
	}
}