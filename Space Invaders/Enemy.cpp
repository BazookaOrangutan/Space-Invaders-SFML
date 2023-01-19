#include "Enemy.h"

Enemy::Enemy(std::string type)
{
	texture.loadFromFile("img\\enemy" + type + ".png");
	sprite.setTexture(texture);
}

void Enemy::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

sf::Vector2f Enemy::getPosition()
{
	return sprite.getPosition();
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
