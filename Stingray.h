#pragma once
#include "Enemy.h"

class Stingray : public Enemy

{

public:
	Stingray(float aSize, int aDamage, int aSpeed);
	void move();
};

