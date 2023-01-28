#pragma once
#include <SFML/Graphics.hpp>
#include "SetProject.h"
class Ship
{
	sf::Sprite sprite;
	sf::Texture texture;
	float a = 70;
	float b = 40;
public:
	Ship();
	void move(float x, float y);
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	void setSprite(std::string path);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getRect(sf::Vector2f v);
};

