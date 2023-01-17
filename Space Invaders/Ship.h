#pragma once
#include <SFML/Graphics.hpp>
#include "SetProject.h"
class Ship
{
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Ship();
	void move(float x, float y);
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	void draw(sf::RenderWindow& window);
};

