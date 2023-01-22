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

	createEnemyes();
	
	//en = new Enemy("1");
	//en->setPosition(150, 200);
	
	bullet = new Ammunition(bulletTexture);
	bullet->setPosition(-100, -100);
	
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
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bullet->getPosition().y < 0) {
		bullet = new Ammunition(bulletTexture);
		bullet->setPosition(ship->getPosition().x + 19, ship->getPosition().y - 15);
		//bullet->move(0, -3);
	}
	bool flag = true;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {

			if (bullet->getRect(bullet->getPosition()).intersects(enemyes[i][j]->getRect(enemyes[i][j]->getPosition()))/*bullet->getSprite().getTextureRect().intersects(enemyes[i][j]->getSprite().getTextureRect()*/) {
				bullet->setPosition(-40, -40);

				if (flag) {
					//delete[]enemyes[i][j];
					enemyes[i][j] = nullptr;
					//delete enemyes[i][j];
					//enemyes[i][j]->setSprite("img\\shipM.png"); 
					flag = false;
				}
				else {
					enemyes[i][j]->setSprite("img\\enemy1.png"); 
					flag = true;
				}
			}
		}
	}
	
} 

void Field::update()
{
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 800; 


	bullet->move(0, -3);
	lifesText.setString("Lifes: " + std::to_string(lifes));
	scoreText.setString("Score: " + std::to_string(score));
	//en->move(1, 0);
	if (enemyes[0][4]->getPosition().x <= WIDTH_W - 75) {
		currentFrame += 0.005 * time;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (enemyes[i][j] != nullptr)
				{
					enemyes[i][j]->move(0.5, 0);
					//if (currentFrame > 3) enemyes[i][j]->setSprite("img\\enemy" + enemyesStr[i][j] + "anim.png");
					//enemyes[i][j]->setSprite("img\\enemy" + enemyesStr[i][j] + ".png");
				}
				
			}
		}
	}
}

void Field::render()
{
	window.clear();
	ship->draw(window);
	window.draw(scoreText);
	window.draw(lifesText);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (enemyes[i][j]!=nullptr) enemyes[i][j]->draw(window);
		}
	}

	bullet->draw(window);
	
	//en->draw(window);
	window.display();
}

void Field::createEnemyes()
{
	enemyes = new Enemy * *[row];
	for (int i = 0; i < row; i++) {
		enemyes[i] = new Enemy * [column];
		for (int j = 0; j < column; j++) {
			enemyes[i][j] = new Enemy(enemyesStr[i][j]);
			enemyes[i][j]->setPosition(75 * j, 75 * i);
		}
	}

}
