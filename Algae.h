#pragma once
#include "Enemy.h"
class Algae: public Enemy
{
private:
	float maxBob;
	float bob;

public:
	Algae(float aSize, int aDamage, float aSpeed);
	void move();
};

