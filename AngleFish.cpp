#include "AngleFish.h"

AngleFish::AngleFish(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	texture.loadFromFile("assets/AngleFish.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 32, 32));
	animationSpeed = 6;
	maxPhase = animationSpeed * 4;
	pointsGained = 6;
	int op = rand() % 2;
	if (op == 0) op = -1;
	direction = op;
	funcX = 0;
	dirY = 1;
	interval = (rand()%100) + 50;
}

void AngleFish::move()
{
	if (enemy.getPosition().x < -150) {
		int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
		enemy.setPosition(sf::Vector2f(-150, (float)posY));
		direction = 1;
		funcX = 0;
		dirY = 1;
		interval = (rand() % 100) + 50;
	}
	else if (enemy.getPosition().x > 4950) {
		int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
		enemy.setPosition(sf::Vector2f(4950, (float)posY));
		direction = -1;
		funcX = 0;
		dirY = 1;
		interval = (rand() % 100) + 50;
	}
	if (funcX != 0 && (int)funcX % interval == 0) {
		if (dirY == 1) {
			dirY = -1;
		}
		else dirY = 1;
	}
	int op = speed / sqrt(2);
	funcX += op;
	enemy.move(sf::Vector2f(direction * op, dirY*op));
	enemy.setScale(-1 * direction * size*0.75, size*0.75);

}
