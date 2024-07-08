#include "Octopus.h"

Octopus::Octopus(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	texture.loadFromFile("assets/Octopus.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 32, 32));
	animationSpeed = 4;
	maxPhase = 3 * animationSpeed;
	pointsGained = 6;
	enemy.setScale(size*0.75, size*0.75);
}

void Octopus::move()
{
	if (enemy.getPosition().y <= - 100) {
		int posX = rand()%bckgrWidth;
		enemy.setPosition(sf::Vector2f{ (float)posX, 1180 });
	}
	else {
		enemy.move(sf::Vector2f{0,(float)speed*-1});
	}
}
