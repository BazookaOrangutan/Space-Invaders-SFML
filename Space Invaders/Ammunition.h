#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SetProject.h"
class Ammunition
{
	sf::Sprite sprite;
	sf::Texture texture;
	sf::FloatRect rect;
	float rectX = 0;
	float rectY = 0;
	float a = 35;
public:
	Ammunition(std::string path);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void move(float x, float y);
	sf::Sprite getSprite();
	void setTextureRect(sf::IntRect rect);
	sf::FloatRect getRect(sf::Vector2f v);
};

