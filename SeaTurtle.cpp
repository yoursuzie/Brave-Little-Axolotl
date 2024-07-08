#include "SeaTurtle.h"

SeaTurtle::SeaTurtle(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	texture.loadFromFile("assets/seaturtle.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 27, 17));
	animationSpeed = 10;
	maxPhase = 8 * animationSpeed;
	pointsGained = 10;
	int op = rand() % 2;
	if (op == 0) op = -1;
	direction = op;
}

void SeaTurtle::move()
{
	if (enemy.getPosition().x < -200) {
		int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
		enemy.setPosition(sf::Vector2f{ -200, (float)posY });
		direction = 1;
	}
	else if (enemy.getPosition().x > 5000) {
		int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
		enemy.setPosition(sf::Vector2f{5000, (float)posY });
		direction = -1;
	}
	else {
		enemy.move(sf::Vector2f{ (float)speed * direction, 0 });
	}
	enemy.setScale(-1*direction*size*1.41, size*1.41);
}
