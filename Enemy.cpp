#include "Enemy.h"


Enemy::Enemy(float aSize, int aDamage, float aSpeed)
{
	pointsGained = 1;
	size = aSize;
	damage = aDamage;
	speed = aSpeed;
	direction = rand() % 2;
	if (direction == 0) direction = -1;
	phase = 0;
	enemy.setScale(size, size);
	bckgrHeight = 1080;
	bckgrWidth = 4800;
	margin = 150;
}

void Enemy::move()
{
	enemy.move(sf::Vector2f{(float)5 * direction, 0 });
	
}

void Enemy::setPosition(sf::Vector2f aPos)
{
	enemy.setPosition(aPos);
}

void Enemy::drawOnWindow(sf::RenderWindow& window)
{
	phase++;
	if (phase > maxPhase) {
		phase = 0;
	}

	if (phase % animationSpeed == 0) {
		int op = phase / animationSpeed;
		enemy.setTextureRect(sf::IntRect(enemy.getLocalBounds().width * op, 0, enemy.getLocalBounds().width, enemy.getLocalBounds().height));
	}

	window.draw(enemy);

	
}

sf::FloatRect Enemy::getBounds() const
{
	return enemy.getGlobalBounds();
}

float Enemy::getPoints() const
{
	return pointsGained;
}

float Enemy::getSize() const
{
	return size;
}

int Enemy::getDamage() const
{
	return damage;
}

sf::Vector2f operator>(sf::Vector2f& vector, int length)
{
	float prop = vector.x / vector.y;
	int sgnX = 1, sgnY = 1;
	if (vector.x < 0) sgnX = -1;
	if (vector.y < 0) sgnY = -1;
	vector.x = sgnX * sqrt(pow(length, 2) / (1 + 1 / pow(prop, 2)));
	vector.y = sgnY * sqrt(pow(length, 2) / (1 + pow(prop, 2)));

	return vector;
}
