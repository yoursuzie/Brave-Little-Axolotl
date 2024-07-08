#include "PowerUps.h"


PowerUps::PowerUps()
{
	isSpawned = false;
	hpTxt.loadFromFile("assets/HpUp.png");
	multprTxt.loadFromFile("assets/ScoreMultiplier.png");
	shieldTxt.loadFromFile("assets/BubbleShield.png");
	bckgrHeight = 1080;
	bckgrWidth = 4800;
	powerUp.setScale(2, 2);
	lastPowerUp = clock();
	cooldown = (rand() % 25000) + 5000;
	margin = 150;
}

void PowerUps::spawn()
{
	if (isSpawned == false && clock() - lastPowerUp > cooldown) {
		int op = rand() % 101;
		bool spawn = false;
		if (op <= 3) {
			powerUp.setTexture(hpTxt);
			spawn = true;
			currentType = type::HP;
		}
		else if (op <= 6) {
			powerUp.setTexture(multprTxt);
			spawn = true;
			currentType = type::MULTPR;
		}
		else if(op <= 9) {
			powerUp.setTexture(shieldTxt);
			spawn = true;
			currentType = type::SHIELD;
		}
		if (spawn) {
			int posX = (rand() % (bckgrWidth - 2 * margin)) + margin;
			int posY = (rand() % (bckgrHeight - 2 * margin)) + margin;
			isSpawned = true;
			powerUp.setPosition((float)posX, (float)posY);
		}
	}
}

int PowerUps::checkCollision(sf::FloatRect playerBounds)
{
	if (isSpawned && powerUp.getGlobalBounds().intersects(playerBounds)) {
		lastPowerUp = clock();
		cooldown = (rand() % 25000) + 5000;
		if (currentType==type::HP) {
			isSpawned = false;
			return 1;
		}

		else if (currentType == type::MULTPR) {
			isSpawned = false;
			return 2;
		}

		else {
			isSpawned = false;
			return 3;

		}
	}
	return 0;
}


void PowerUps::draw(sf::RenderWindow& window)
{

	if (isSpawned == true) window.draw(powerUp);
}
