#include "Algae.h"

Algae::Algae(float aSize, int aDamage, float aSpeed): Enemy(aSize, aDamage, aSpeed)
{
	texture.loadFromFile("assets/Algae.png");
	enemy.setTexture(texture);
	pointsGained = aSize;
	enemy.setScale(size * 3, size * 3);
	direction = rand()%2;
	if (direction == 0) direction = -1;
	maxBob = 10;
	bob = (rand()%21)-10;
}

void Algae::move()
{
	enemy.move(0, direction * speed);
	bob += direction * speed;
	if (abs(bob) >= maxBob) {
		if (direction == 1) direction = -1;
		else direction = 1;
	}
}
