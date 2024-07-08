#pragma once
#include "Enemy.h"
#include "Octopus.h"
#include "SeaTurtle.h"
#include "RainbowFish.h"
#include "AngleFish.h"
#include "CrownFish.h"
#include "Algae.h"
#include "CannonFish.h"
#include "MusketFish.h"
#include "StarFish.h"
#include "Stingray.h"
#include "HocusPocusFish.h"
#include "Shark.h"
#include "Garbage.h"
#include <vector>


class EnemyArray
{
private:
	std::vector <Enemy*> enemiesArray;
	int maxSizeEnemy; //ile max moze byc przeciwnikow
	std::vector <Enemy*> floatingArray;
	std::vector <Shark*> sharksArray;
	int sharkLimit;
	int garbageLimit;
	int garbageCount;
	int maxSizeFloating;
	int bckgrWidth;
	int bckgrHeight;
	int margin;

	

public:
	EnemyArray(int aSize);
	void spawn();
	void drawAll(sf::RenderWindow& window);
	void moveAll(sf::Vector2f);
	void axolotlDead();
	float checkCollision(sf::FloatRect, float);
	bool isEmpty();
	bool isSharkChasing();
};

