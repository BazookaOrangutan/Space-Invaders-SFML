#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SetProject.h"
class Ammunition
{
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Ammunition(std::string path);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void move(float x, float y);
	
};

