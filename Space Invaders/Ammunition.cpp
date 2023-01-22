#include "Ammunition.h"



Ammunition::Ammunition(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0,0,35,35));
}

void Ammunition::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

sf::Vector2f Ammunition::getPosition()
{
	return sprite.getPosition();
}

void Ammunition::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Ammunition::move(float x, float y)
{
	sprite.move(x, y);
}

sf::Sprite Ammunition::getSprite()
{
	return sprite;
}

sf::FloatRect Ammunition::getRect(sf::Vector2f v)
{
	rectX = v.x;
	rectY = v.y;
	return sf::FloatRect(rectX, rectY, a, a);
}


