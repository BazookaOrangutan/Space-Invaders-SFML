#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
public:
	Enemy(std::string type);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
};

