#include "Enemy.h"

Enemy::Enemy(std::string type)
{
	texture.loadFromFile("img\\enemy" + type + ".png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0,0,75,75));
	
}

Enemy::~Enemy()
{
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

void Enemy::setSprite(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

sf::Sprite Enemy::getSprite()
{
	return sprite;
}

void Enemy::move(float x, float y)
{
	sprite.move(x, y);
}

sf::FloatRect Enemy::getRect(sf::Vector2f v)
{
	rectX = v.x;
	rectY = v.y;
	return sf::FloatRect(rectX, rectY, a, a);
}


