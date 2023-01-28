#pragma once
#include <SFML/Graphics.hpp>
#include "SetProject.h"
#include <string>
class Enemy
{
	sf::Texture texture;
	sf::Sprite sprite;
	std::string type;
	float rectX = 0;
	float rectY = 0;
	float a = 70;
	float b = 43;
public:
	Enemy(std::string type);
	sf::IntRect setRectMeaning();
	std::string getType();
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void setSprite(std::string path);
	sf::Sprite getSprite();
	void move(float x, float y);
	sf::FloatRect getRect(sf::Vector2f v);

};

