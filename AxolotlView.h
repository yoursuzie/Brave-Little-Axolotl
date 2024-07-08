#pragma once
#include "Axolotl.h"
#include "HealthBar.h"
#include "EnemyArray.h"
#include "PowerUps.h"

class AxolotlView
{
private:
	Axolotl& axolotl;
	HealthBar hb;
	EnemyArray& array;
	PowerUps& powerUp;

	sf::Texture backgroundTxt;
	sf::Sprite background;
	sf::RenderWindow& window;
	sf::View& camera;
	sf::Font font;
	sf::Color bbyBlue;
	sf::Sprite endScreen;
	sf::Texture blackOut;
	sf::Text defeat;
	sf::Text win;
	sf::Text explanation;

	bool axolotlDead;
	bool axolotlSleeping;

	

public:
	AxolotlView(Axolotl& axolotl, sf::RenderWindow& window, sf::View &camera, EnemyArray& array, PowerUps& powerUp);
	void display();
	void pauseScreen();
	void startScreen();
	void setAxolotlDead(bool);
	void setAxolotlSleep(bool);
};

