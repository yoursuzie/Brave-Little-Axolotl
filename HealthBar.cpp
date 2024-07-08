#include "HealthBar.h"

HealthBar::HealthBar()
{
	healthTexture.loadFromFile("assets/HealthBars.png");
	healthSprite.setTexture(healthTexture);
	healthSprite.setTextureRect(sf::IntRect(0, 0, 128, 32));
	healthSprite.setOrigin(healthSprite.getLocalBounds().width, 0);
	healthSprite.setScale(4, 4);
}

void HealthBar::draw(sf::RenderWindow& window, int aHealth)
{
	int row;
	if (aHealth > 8) row = 0;
	else if (aHealth < 0) row = 8;
	else row = abs(aHealth - 8);
	healthSprite.setTexture(healthTexture);
	healthSprite.setTextureRect(sf::IntRect(0, row * 32, 128, 32));
	window.draw(healthSprite);
}

void HealthBar::setPosition(sf::Vector2f aPos)
{
	healthSprite.setPosition(aPos);
}
