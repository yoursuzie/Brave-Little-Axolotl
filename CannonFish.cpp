#include "CannonFish.h"

CannonFish::CannonFish(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	size = aSize;
	damage = aDamage;
	speed = aSpeed;
	animationSpeed = 6;
	maxPhase = animationSpeed * 5;
	pointsGained = 10;
	direction = 0;
	texture.loadFromFile("assets/CannonFish.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 25, 26));
}

void CannonFish::setPosition(sf::Vector2f aPos)
{
	enemy.setPosition(aPos);

	dest.x = rand() % bckgrWidth;
	dest.y = rand() % bckgrHeight;

	movement.x = dest.x - aPos.x;
	movement.y = dest.y - aPos.y;


	float prop = movement.x / movement.y;
	int sgnX = 1, sgnY = 1;
	if (movement.x < 0) sgnX = -1;
	if (movement.y < 0) sgnY = -1;
	movement.x = sgnX * sqrt(pow(speed, 2) / (1 + 1 / pow(prop, 2)));
	movement.y = sgnY * sqrt(pow(speed, 2) / (1 + pow(prop, 2)));
	direction = sgnX;

}

void CannonFish::move()
{
	if (sqrt(pow(enemy.getPosition().x - dest.x, 2) + pow(enemy.getPosition().y - dest.y, 2)) <= speed) {

		setPosition(dest);
	}
	else {
		enemy.move(movement);
	}

	enemy.setScale(-1 * direction * size * 0.92, size * 0.92);
}
