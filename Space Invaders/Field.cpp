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
	
	winText.setString("YOU WON!");
	winText.setFillColor(color);
	winText.setFont(font);
	winText.setCharacterSize(endTextSize);
	winText.setPosition(WIDTH_W / 2 - winText.getCharacterSize() / 2 - 125, HIGHT_W / 2 - winText.getCharacterSize() / 2);

	gameOverText.setString("GAME OVER");
	gameOverText.setFillColor(color);
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(endTextSize);
	gameOverText.setPosition(WIDTH_W / 2 - winText.getCharacterSize() / 2 - 170, HIGHT_W / 2 - winText.getCharacterSize() / 2);
	
	createEnemyes();
	createBombs();

	//en = new Enemy("1");
	//en->setPosition(150, 200);

	bullet = new Ammunition(bulletTexture, 25, 35);
	bullet->setPosition(-100, -100);

	time = clock.getElapsedTime().asMicroseconds();
	time = time / 800;
	currentFrame = 0;
	
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
		bullet->setPosition(ship->getPosition().x + 19, ship->getPosition().y - 15);
	}
	for (int i = 0; i < row * column; i++) {
		if (bullet->getRect(bullet->getPosition()).intersects(enemyes[i]->getRect(enemyes[i]->getPosition()))) {
			bullet->setPosition(-40, -40);
			enemyes[i]->setPosition(-200, -200);
			if (0 <= i < 5) {
				if (i == leftEnemy) {
					leftEnemy += differenceLeft; differenceLeft = 1;
				}
				else if (i == rightEnemy) rightEnemy -= differenceRight;
			}
			score += 250;
			//enemyDeath(i);
		}
	}
	for (int i = 0; i < row * column; i++) {
		if (ship->getRect(ship->getPosition()).intersects(bombs[i]->getRect(bombs[i]->getPosition()))) {
			bombs[i]->setPosition(-100, 800);
			lifes -= 1;
		}
		if (bullet->getRect(bullet->getPosition()).intersects(bombs[i]->getRect(bombs[i]->getPosition()))) {
			bombs[i]->setPosition(-100, 800);
			bullet->setPosition(-100, -100);
		}
	}
	if (score == 3750) {
		ship->move(0, -5);
	}
	
	if (lifes <= 0) {
		ship->move(0, 1000);
	}
} 

void Field::update()
{ 
	scoreText.setPosition(WIDTH_W - 130 - std::to_string(score).size() * 10, HIGHT_W - 32);
	bullet->move(0, -3);
	lifesText.setString("Lifes: " + std::to_string(lifes));
	scoreText.setString("Score: " + std::to_string(score));
	//en->move(1, 0);
	for (int i = 0; i < bombs.size(); i++) {
		bombs[i]->move(0, 3);
	}
	if (flag1) {
		if (enemyes[rightEnemy]->getPosition().x <= WIDTH_W - 75) {
			for (int i = 0; i < row * column; i++) {
				if (enemyes[i] != nullptr)
				{
					if (enemyes[i]->getPosition().y > -1) enemyes[i]->move(0.5, 0);
					enemyes[i]->setSprite("img/enemy" + enemyes[i]->getType() + ".png");
				}
			}
		}
		else { flag1 = false; }
	}
	if (!flag1) {
		if (enemyes[leftEnemy]->getPosition().x > 10) {
			for (int i = 0; i < row * column; i++) {
				if (enemyes[i] != nullptr)
				{
					if (enemyes[i]->getPosition().y > -1) enemyes[i]->move(-0.5, 0);
					enemyes[i]->setSprite("img/enemy" + enemyes[i]->getType() + ".png");
				}
			}
		}
		else { flag1 = true; }
	}
	if (counter < random(1, 5)) {
		int index = random(0, 14);
		if (bombs[index]->getPosition().y > HIGHT_W) {
			bombs[index]->setPosition(enemyes[index]->getPosition().x + 10, enemyes[index]->getPosition().y);

		}
		counter++;
	}
	currentFrame += time;
	if (currentFrame > 1000) {
		counter = 0;
		currentFrame = 0;
	}

}

void Field::render()
{
	window.clear();
	ship->draw(window);
	window.draw(scoreText);
	window.draw(lifesText);

	for (int i = 0; i < enemyes.size(); i++) {
		enemyes[i]->draw(window);
	}
	for (int i = 0; i < bombs.size(); i++) {
		bombs[i]->draw(window);
	}

	bullet->draw(window);

	if (score == 3750) window.draw(winText);
	if (lifes <= 0) window.draw(gameOverText);
	
	//en->draw(window);
	window.display();
}

void Field::createEnemyes()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			enemyes.push_back(new Enemy(enemyesStr[i][j]));
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			switch (i + 1) {
			case(1): enemyes[j]->setPosition(75 * j, 75 * i);
			case(2): enemyes[j + 5]->setPosition(75 * j, 75 * i);
			case(3): enemyes[j + 10]->setPosition(75 * j, 75 * i);
			}
		}
	}
}

void Field::createBombs()
{
	for (int i = 0; i < enemyes.size(); i++) {
		bombs.push_back(new Ammunition("img/bombM.png", 40, 40));
		bombs[i]->setPosition(-100, 800);	
	}
}

void Field::animationEnemyes()
{
	bool flag = true;
	float animTime1 = 0, animTime2 = 0;

	animTime1 += time ;
	for (int i = 0; i < enemyes.size(); i++) {
		if (animTime1 > 1000) {
			enemyes[i]->setSprite("img\\enemy" + enemyes[i]->getType() + "anim.png");
			/*while (currentFrame > 0) {
				currentFrame -= time;
			}
			if (currentFrame <= 0) {
				enemyes[i]->setSprite("img\\enemy" + enemyes[i]->getType() + ".png");
			}*/
			animTime1 = 0;
		}
	}
	/*animTime2 += time;
	for (int i = 0; i < enemyes.size(); i++) {
		if (animTime2 > 5000) {
			enemyes[i]->setSprite("img\\enemy" + enemyes[i]->getType() + ".png");
			animTime2 = 0;
		}
	}*/

}

void Field::enemyDeath(int index)
{
	while (currentFrame < 3000) {
		currentFrame += time;
		bullet->setPosition(-40, -40);
		//score += 250;
		enemyes[index]->setSprite("img/explosion.png");
		if (currentFrame >= 3000) {
			enemyes[index]->setPosition(-200, -200);
			
		}
	}
	currentFrame = 0;
}
