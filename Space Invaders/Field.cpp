#include "Field.h"

Field::Field() : window(sf::VideoMode(WIDTH_W, HIGHT_W), "Space Invaders")
{
	font.loadFromFile("fonts\\retro-land-mayhem.ttf");
	ship = new Ship();
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setFillColor(color);
	scoreText.setFont(font);
	scoreText.setCharacterSize(characterSize);
	scoreText.setPosition(WIDTH_W - 130, HIGHT_W - 32);
	lifesText.setString("Lifes: " + std::to_string(lifes));
	lifesText.setFillColor(color);
	lifesText.setFont(font);
	lifesText.setCharacterSize(characterSize);
	lifesText.setPosition(WIDTH_W - 475, HIGHT_W - 32);
	en = new Enemy("1");
}

void Field::run()
{
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Field::processEvents()
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		
	}
	if (ship->getPosition().x > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			ship->move(-3, 0);
		}
	}
	if (ship->getPosition().x < WIDTH_W - 70) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			ship->move(3, 0);
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		bullet = new Ammunition(bulletTexture);
		bullet->setPosition(ship->getPosition().x + 19, ship->getPosition().y - 15);
		bullet->move(0, -3);
	}
	/*if (bullet->getPosition() == en->getPosition()) {
		delete en;
	}*/
} 

void Field::update()
{
	if (bullet != nullptr) {
		bullet->move(0, -3);
	}

}

void Field::render()
{
	window.clear();
	ship->draw(window);
	window.draw(scoreText);
	window.draw(lifesText);
	if (bullet != nullptr) {
		bullet->draw(window);
	}
	en->draw(window);
	window.display();
}
