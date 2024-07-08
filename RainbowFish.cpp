#include "RainbowFish.h"

RainbowFish::RainbowFish(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	texture.loadFromFile("assets/RainbowFish.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 32, 16));
	animationSpeed = 6;
	maxPhase = 5 * animationSpeed;
	pointsGained = 6;
	int op = rand() % 2;
	if (op == 0) op = -1;
	direction = op;
	funcX = rand()% 158; //polozenie na funkcji
	
}

void RainbowFish::move()
{
	if (enemy.getPosition().x < -150) {
		int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
		enemy.setPosition(sf::Vector2f(-150, (float)posY));
		direction = 1;
		funcX = rand() % 158;

	}
	else if (enemy.getPosition().x > 4950) {
		int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
		enemy.setPosition(sf::Vector2f(4950, (float)posY));
		direction = -1;
		funcX = rand() % 158;
	}

	float funcY = 150 * abs(sin(funcX / 50));
	float funcX2 = funcX;
	float funcY2 = funcY; //polozenie na funkcji po wykonanym ruchu

	while (sqrt(pow(funcX2 - funcX, 2) + pow(funcY2 - funcY, 2)) < speed) {
		funcX2 += 0.5;
		funcY2 = 150 * abs(sin(funcX2 / 50));
	}
	enemy.move(sf::Vector2f((funcX2 - funcX) * direction, -1*(funcY2 - funcY)));
	funcX = funcX2;
	enemy.setScale(-1 * direction * size*0.975, size*0.975);

}
