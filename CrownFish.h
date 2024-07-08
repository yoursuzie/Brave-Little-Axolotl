#pragma once
#include "Enemy.h"
class CrownFish : public Enemy 
{
private:
	sf::Vector2f dest;
	sf::Vector2f movement;

public:
	CrownFish(float aSize, int aDamage, int aSpeed);
	void setPosition(sf::Vector2f aPos);
	void move();
};

