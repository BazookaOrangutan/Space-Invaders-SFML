#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "SetProject.h"
#include "Enemy.h"
#include "Ammunition.h"

class Field
{
	sf::RenderWindow window;
	sf::Event event;

	int score = 0;
	sf::Text scoreText;
	sf::Color color = sf::Color(0,255,21,255);
	int lifes = 2;
	sf::Text lifesText;
	sf::Font font;
	int characterSize = WIDTH_W * HIGHT_W / 15000; //size == 20
	
	std::string bulletTexture = "img\\bulletM.png";
	std::string bombTexture;
	Ammunition** bombs = nullptr;
	Ammunition* bullet = nullptr;
	Enemy* en = nullptr;
	Enemy** enemyes = nullptr;
	Ship* ship;
	sf::Sprite spriteShip;
	std::string enemyesStr[3][5] = { {"2", "2", "2", "2", "2"},
									 {"2", "2", "2", "2", "2"},
									 {"1", "1", "1", "1", "1"} };
	std::string enemy1[2];
	std::string enemy2[2];
	
public:
	Field();
	void run();
	void processEvents();
	void update();
	void render();

};

