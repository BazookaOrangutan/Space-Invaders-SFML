#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "SetProject.h"
#include "Enemy.h"
#include "Ammunition.h"
#include <string>
#include <vector>

#define random(a, b) a + rand()%(b - a + 1)

class Field
{
	sf::RenderWindow window;
	sf::Event event;

	sf::Color color = sf::Color(0,255,21,255);
	int lifes = 3, score = 0;
	sf::Text lifesText, scoreText, winText, gameOverText;
	sf::Font font;
	int endTextSize = WIDTH_W * HIGHT_W / 5000;
	int characterSize = WIDTH_W * HIGHT_W / 15000; //size == 20
	
	std::string bulletTexture = "img\\bulletM.png";
	std::string bombTexture;
	std::vector<Ammunition*> bombs;
	Ammunition* bullet = nullptr;
	Enemy* en = nullptr;
	std::vector<Enemy*> enemyes;
	int row = 3, column = 5;
	int leftEnemy = 0, rightEnemy = column - 1, differenceLeft = 1, differenceRight = 1;
	bool flag1 = true;
	Ship* ship;
	
	std::string enemyesStr[3][5] = { {"2", "2", "2", "2", "2"},
									 {"2", "2", "2", "2", "2"},
									 {"1", "1", "1", "1", "1"} };

	sf::Clock clock;
	float currentFrame;
	float time;
	int counter = 0;

public:
	Field();
	void run();
	void processEvents();
	void update();
	void render();
private:
	void createEnemyes();
	void createBombs();
	void animationEnemyes();
	void enemyDeath(int index);

};

