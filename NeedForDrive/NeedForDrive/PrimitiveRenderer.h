#pragma once
#include "Engine.h"

class PrimitiveRenderer {
public:
	PrimitiveRenderer();
	~PrimitiveRenderer();
	void drawSpectators(sf::RenderWindow& window);
};