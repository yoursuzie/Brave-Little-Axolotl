#include "HocusPocusFish.h"


HocusPocusFish::HocusPocusFish(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	size = aSize;
	damage = aDamage;
	speed = aSpeed;
	animationSpeed = 8;
	maxPhase = animationSpeed * 3;
	pointsGained = 14;
	texture.loadFromFile("assets/HocusPocusFish.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 28, 23));
	enemy.setOrigin(enemy.getLocalBounds().width/2, enemy.getLocalBounds().height);
	timeIdle = time(nullptr);
	waitTime = rand() % 10;
	destX = rand() % bckgrWidth;
	if (destX > enemy.getPosition().x) direction = 1;
	else direction = -1;
	
}

void HocusPocusFish::move()
{
	if (direction == 1 && enemy.getPosition().x > bckgrWidth) {
		direction = -1;
		destX = 4600;
	}

	if (direction == -1 && enemy.getPosition().x < 0) {
		direction = 1;
		destX = 200;
	}

	if (time(nullptr) - timeIdle > waitTime) {
		if (abs( destX - enemy.getPosition().x) < speed)
		{
			timeIdle = time(nullptr);

			destX = rand() % bckgrWidth;
			if (destX > enemy.getPosition().x) direction = 1;
			else direction = -1;
		}
		else 
		{
			enemy.move(sf::Vector2f(direction * speed, 0));
		}
	}

	enemy.setScale(-1 * direction * size * 1.04, size * 1.04);
	
}
