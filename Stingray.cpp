#include "Stingray.h"

Stingray::Stingray(float aSize, int aDamage, int aSpeed): Enemy(aSize, aDamage, aSpeed)
{
	size = aSize;
	damage = aDamage;
	speed = aSpeed;
	animationSpeed = 8;
	maxPhase = animationSpeed * 3;
	pointsGained = 14;
	texture.loadFromFile("assets/Stingray.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 29, 5));
	enemy.setOrigin(0, enemy.getLocalBounds().height);
	
}


void Stingray::move()
{
	if (enemy.getPosition().x < -100) {
		int posY = bckgrHeight;
		enemy.setPosition(sf::Vector2f{ -100, (float)posY });
		direction = 1;
	}
	else if (enemy.getPosition().x > 5000) {
		int posY = bckgrHeight;
		enemy.setPosition(sf::Vector2f{ 5000, (float)posY });
		direction = -1;
	}
	else {
		enemy.move(sf::Vector2f{ (float)speed * direction, 0 });
	}

	enemy.setScale(-1 * direction * size * 1.7, size * 1.7);

}
