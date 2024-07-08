#pragma once
#include "Enemy.h"

class AngleFish :public Enemy
{
private:
	float funcX;
	int dirY;
	int interval;

public:
	AngleFish(float aSize, int aDamage, int aSpeed);
	void move();
};

