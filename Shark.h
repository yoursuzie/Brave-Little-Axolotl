#pragma once
#include "Enemy.h"

class Shark : public Enemy 
{
private:
	int chargeSpeed;
	int visionRange;
	int eatRange;
	bool swimOut;
	bool kill;
	clock_t spawnTime;
	sf::Texture trigger;
	sf::Vector2f targetPos;
	bool isTriggered;

public:
	Shark(float aSize, int aDamage, int aSpeed);
	void moveShark(sf::Vector2f aPlayerPos);
	bool doKill();
	void swimOutSet(bool);
	bool getTrigger();
};

