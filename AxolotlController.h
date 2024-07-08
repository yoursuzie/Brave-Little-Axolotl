#pragma once
#include "AxolotlView.h"
#include "EnemyArray.h"
#include "PowerUps.h"
#include "SoundEffects.h"


class AxolotlController
{
private:
	Axolotl& axolotl;
	AxolotlView view;
	EnemyArray array;
	PowerUps powerUp;
	SoundEffects sound;
	sf::View camera;
	sf::RenderWindow window;
	sf::Image pointerTxt;
	sf::Cursor pointer;
	std::clock_t cooldown;
	std::clock_t powerUpTime1;
	std::clock_t powerUpTime2;
	void update();
	void defeatScreen();
	void winScreen();
	int multiplier;
	bool doSpawnFish;
	bool win;
	bool changeSFX;
	bool dead;
	bool hasWon;


public:
	AxolotlController(Axolotl& aAxolotl);
	void play();
	

};

