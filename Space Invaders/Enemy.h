#pragma once
#include <SFML/Graphics.hpp>
#include "SetProject.h"
class Enemy
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::FloatRect rect;
	float rectX = 0;
	float rectY = 0;
	float a = 60;
public:
	Enemy(std::string type);
	~Enemy();
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void setSprite(std::string path);
	sf::Sprite getSprite();
	void move(float x, float y);
	void setTextureRect(sf::IntRect rect);
	sf::FloatRect getRect(sf::Vector2f v);

};

