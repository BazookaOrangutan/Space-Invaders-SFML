#include "Enemy.h"

Enemy::Enemy(std::string type)
{
	this->type = type;
	texture.loadFromFile("img\\enemy" + type + ".png");
	sprite.setTexture(texture);
	//sprite.setTextureRect(setRectMeaning()); 
	sprite.setTextureRect(sf::IntRect(11,0,60,65));

}

sf::IntRect Enemy::setRectMeaning()
{
	switch (stoi(type)) {
	case(1): rectX = 0; rectY = 0; a = 55; b = 40;
	case(2): rectX = 0; rectY = 0; a = 40; b = 40;
	}
	return sf::IntRect(rectX, rectY, a, b);
}

std::string Enemy::getType()
{
	return type;
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
	/*rectX = v.x;
	rectY = v.y;*/
	return sf::FloatRect(v.x - 40, v.y, a - 10, b);
}


