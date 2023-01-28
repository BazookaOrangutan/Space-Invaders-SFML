#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SetProject.h"
class Ammunition
{
	sf::Sprite sprite;
	sf::Texture texture;
	float rectX = 0;
	float rectY = 0;
	float a = 35;
	float b = 25;
public:
	Ammunition(std::string path, float a, float b);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void move(float x, float y);
	sf::Sprite getSprite();
	sf::FloatRect getRect(sf::Vector2f v);
};

