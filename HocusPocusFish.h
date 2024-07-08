#pragma once
#include "Enemy.h"

class HocusPocusFish : public Enemy
{
private:
	int destX;
	clock_t timeIdle;
	int waitTime;

public:
	HocusPocusFish(float aSize, int aDamage, int aSpeed);
	void move();
};

