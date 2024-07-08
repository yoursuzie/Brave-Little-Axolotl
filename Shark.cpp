#include "Shark.h"

Shark::Shark(float aSize, int aDamage, int aSpeed) : Enemy(aSize, aDamage, aSpeed)
{
	size = aSize;
	damage = aDamage;
	speed = aSpeed;
	chargeSpeed = speed * 1.5;
	pointsGained = 100;
	animationSpeed = 5;
	maxPhase = animationSpeed * 5;
	texture.loadFromFile("assets/SharkClosed.png");
	trigger.loadFromFile("assets/SharkOpen.png");
	enemy.setTexture(texture);
	enemy.setTextureRect(sf::IntRect(0, 0, 31, 14));
	enemy.setOrigin(enemy.getLocalBounds().width / 2, enemy.getLocalBounds().height / 2);
	targetPos.x = rand() % bckgrWidth;
	targetPos.y = rand() % bckgrHeight;
	visionRange = 512;
	eatRange = visionRange / 2;
	if (enemy.getPosition().x < targetPos.x) direction = 1;
	else direction = -1;
	swimOut = false;
	kill = false;
	isTriggered = false;
	spawnTime = time(nullptr);
}

void Shark::moveShark(sf::Vector2f aPlayerPos)
{
	float distance = sqrt(pow(aPlayerPos.x - enemy.getPosition().x, 2) + pow(aPlayerPos.y - enemy.getPosition().y, 2));

	if (distance < visionRange && !swimOut) 
	{
		isTriggered = true;

		if (distance < eatRange) {
			enemy.setTexture(trigger);
		}
		else {
			enemy.setTexture(texture);
		}
		if (distance >= speed) {
			sf::Vector2f toPlayer = aPlayerPos - enemy.getPosition();
			toPlayer > chargeSpeed;
			if (toPlayer.x > 0) direction = 1;
			else direction = -1;
			enemy.move(toPlayer);
		}
		else {
			enemy.setPosition(aPlayerPos);
		}


	}
	else 
	{
		isTriggered = false;

		if (time(nullptr) - spawnTime > 60 && !swimOut) {
			swimOut = true;
			int op = rand() % 2;
			if(op == 0) {
				targetPos = { -200, enemy.getPosition().y};
			}
			else {
				targetPos = { (float)bckgrWidth+200, enemy.getPosition().y };
			}
		}
		float dest = sqrt(pow(enemy.getPosition().x - targetPos.x, 2) + pow(enemy.getPosition().y - targetPos.y, 2));
		if (dest >= speed) 
		{
			sf::Vector2f movement = targetPos - enemy.getPosition();
			movement > speed;
			if (movement.x > 0) direction = 1;
			else direction = -1; 
			enemy.move(movement);

		}
		else 
		{
			if (swimOut) kill = true;
			targetPos.x = rand() % bckgrWidth;
			targetPos.y = rand() % bckgrHeight;

		}
	}

	enemy.setScale(-1 * direction * size, size);
}

bool Shark::doKill()
{
	return kill;
}

void Shark::swimOutSet(bool op)
{
	swimOut = op;
	if (swimOut) {
		enemy.setTexture(texture);
	}
}

bool Shark::getTrigger()
{
	return isTriggered;
}
