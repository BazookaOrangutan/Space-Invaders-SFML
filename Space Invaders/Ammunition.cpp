#include "Ammunition.h"



Ammunition::Ammunition(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	//sprite.setPosition(40, 40);
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
