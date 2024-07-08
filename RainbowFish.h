#pragma once
#include "Enemy.h"

class RainbowFish : public Enemy
{
private:
	float funcX;

public:
	RainbowFish(float aSize, int aDamage, int aSpeed);
	void move();
};

