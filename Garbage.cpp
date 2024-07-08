#include "Garbage.h"

Garbage::Garbage(float aSize, int aDamage, float aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	texture.loadFromFile("assets/Garbage.png");
	enemy.setTexture(texture);
	pointsGained = 0;
	enemy.setScale(2,2);
	direction = rand() % 2;
	if (direction == 0) direction = -1;
	maxBob = 10;
	bob = (rand() % 21) - 10;
}

void Garbage::move()
{
	enemy.move(0, direction * speed);
	bob += direction * speed;
	if (abs(bob) >= maxBob) 
	{
		if (direction == 1) direction = -1;
		else direction = 1;
	}
}
