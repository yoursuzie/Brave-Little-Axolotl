#pragma once
#include "Enemy.h"

class Octopus : public Enemy
{
public:
	Octopus(float aSize, int aDamage, int aSpeed);
	void move();
	
};

