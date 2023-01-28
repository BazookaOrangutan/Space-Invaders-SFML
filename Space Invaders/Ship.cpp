#include "Ship.h"

Ship::Ship()
{
	texture.loadFromFile("img\\shipM.png");
	sprite.setTexture(texture);
	sprite.setPosition(WIDTH_W / 2 - 25, HIGHT_W * 6 / 7);
}

void Ship::move(float x, float y)
{
	sprite.setPosition(sprite.getPosition().x + x, sprite.getPosition().y + y);
}

sf::Vector2f Ship::getPosition()
{
	return sprite.getPosition();
}

sf::Sprite Ship::getSprite()
{
	return sprite;
}

void Ship::setSprite(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

void Ship::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::FloatRect Ship::getRect(sf::Vector2f v)
{
	return sf::FloatRect(v.x - 20, v.y, a - 15, b);
}
