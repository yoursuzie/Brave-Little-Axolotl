#pragma once
#include "Enemy.h"


class SeaTurtle : public Enemy
{
public:
	SeaTurtle(float aSize, int aDamage, int aSpeed);
	void move();

};

