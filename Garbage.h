#pragma once
#include "Enemy.h"

class Garbage : public Enemy
{
private:
	float maxBob;
	float bob;

public:
	Garbage(float aSize, int aDamage, float aSpeed);
	void move();
};

