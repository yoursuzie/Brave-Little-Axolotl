#include "EnemyArray.h"

EnemyArray::EnemyArray(int aSize)
{
	maxSizeEnemy = aSize;
	sharkLimit = 1;
	maxSizeFloating = aSize;
	garbageCount = 0;
	garbageLimit = maxSizeFloating / 3;
	bckgrHeight = 1080;
	bckgrWidth = 4800;
	margin = 200;
}

void EnemyArray::spawn()
{
	while (enemiesArray.size() < maxSizeEnemy) {
		sf::Vector2f pos = { (float)(rand() % bckgrWidth), (float)((rand() %( bckgrHeight - 2*margin))+margin) };
		int op = (rand() % 100)+1;
		if (op <= 2 && sharksArray.size() < sharkLimit) {
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 7.5; //losujemy sobie rozmiar od 7,5 do 8,5
			sharksArray.resize(sharksArray.size() + 1);
			sharksArray.back() = new Shark(size, 8, 3);
			sharksArray.back()->setPosition(pos);
		}
		else if (op <= 18)
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 1.5; //losujemy sobie rozmiar od 1,5 do 2,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new StarFish(size, 1, 3);
			enemiesArray.back()->setPosition(pos);
		}
		else if (op <= 30) {
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 2.5; //losujemy sobie rozmiar od 2,5 do 3,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new Octopus(size, 1, 3);
			enemiesArray.back()->setPosition(pos);
		}
		else if (op <= 42) {
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 2.5; //losujemy sobie rozmiar od 2,5 do 3,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new RainbowFish(size, 1, 5);
			enemiesArray.back()->setPosition(pos);
		}
		else if(op <= 54)
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 2.5; //losujemy sobie rozmiar od 2,5 do 3,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new AngleFish(size, 1, 5);
			enemiesArray.back()->setPosition(pos);
		}
		else if (op <= 66)
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 2.5; //losujemy sobie rozmiar od 2,5 do 3,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new CrownFish(size, 1, 5);
			enemiesArray.back()->setPosition(pos);
		}
		else if(op <= 74)
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 4.5; //losujemy sobie rozmiar od 4,5 do 5,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new CannonFish(size, 1, 2);
			enemiesArray.back()->setPosition(pos);
		}
		else if (op <= 82) {
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 4.5; //losujemy sobie rozmiar od 4,5 do 5,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new SeaTurtle(size, 1, 1);
			enemiesArray.back()->setPosition(pos);
		}
		else if(op <= 90)
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 4.5; //losujemy sobie rozmiar od 4,5 do 5,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new MusketFish(size, 1, 2);
			enemiesArray.back()->setPosition(pos);
		}
		else if (op <= 95)
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 6.5; //losujemy sobie rozmiar od 6,5 do 7,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new Stingray(size, 1, 2);
			enemiesArray.back()->setPosition(sf::Vector2f(pos.x, bckgrHeight));

		}
		else
		{
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 6.5; //losujemy sobie rozmiar od 6,5 do 7,5
			enemiesArray.resize(enemiesArray.size() + 1);
			enemiesArray.back() = new HocusPocusFish(size, 1, 2);
			enemiesArray.back()->setPosition(sf::Vector2f(pos.x, bckgrHeight));
		}
	}

	while (floatingArray.size() < maxSizeFloating) {
		sf::Vector2f pos = { (float)(rand() % (bckgrWidth-2*margin)+margin), (float)((rand() % (bckgrHeight - 2 * margin)) + margin) };
		int op = rand() % 101;
		if (op <= 80 || garbageCount >= garbageLimit) {
			float size = (static_cast <float> (rand()) / static_cast<float>(RAND_MAX)) + 0.5; //losujemy sobie rozmiar od 0,5 do 1,5
			floatingArray.resize(floatingArray.size() + 1);
			floatingArray.back() = new Algae(size, 0, 0.5);
			floatingArray.back()->setPosition(pos);
		}
		else
		{
			floatingArray.resize(floatingArray.size() + 1);
			floatingArray.back() = new Garbage(INT_MAX, 1, 0.5);
			floatingArray.back()->setPosition(pos);
			garbageCount++;
		}
	}
}

void EnemyArray::drawAll(sf::RenderWindow& window)
{
	for (int i = 0; i < sharksArray.size(); i++) {
		sharksArray[i]->drawOnWindow(window);
	}
	for (int i = 0; i < floatingArray.size(); i++) {
		floatingArray[i]->drawOnWindow(window);
	}
	for (int i = 0; i < enemiesArray.size(); i++) {
		enemiesArray[i]->drawOnWindow(window);
	}


}

void EnemyArray::axolotlDead()
{
	for (int i = 0; i < sharksArray.size(); i++) {
		sharksArray[i]->swimOutSet(true);
	}
}

bool EnemyArray::isEmpty()
{
	return enemiesArray.empty() && sharksArray.empty();
}

bool EnemyArray::isSharkChasing()
{
	for (int i = 0; i < sharksArray.size(); i++) {
		if (sharksArray[i]->getTrigger()) {
			return true;
		}
	}
	return false;
}

void EnemyArray::moveAll(sf::Vector2f playerPos)
{
	for (int i = 0; i < enemiesArray.size(); i++) {
		enemiesArray[i]->move();
	}

	for (int i = 0; i < sharksArray.size(); i++) {
		sharksArray[i]->moveShark(playerPos);
		if (sharksArray[i]->doKill()) {
			sharksArray.erase(sharksArray.begin() + i);
		}
	}

	for (int i = 0; i < floatingArray.size(); i++) {
		floatingArray[i]->move();
	}
}

float EnemyArray::checkCollision(sf::FloatRect playerBounds, float playerSize)
{
	float ret = 0;
	for (int i = 0; i < enemiesArray.size(); i++) {
		if (enemiesArray[i]->getBounds().intersects(playerBounds)) {
			if (enemiesArray[i]->getSize() <= playerSize) {
				ret = enemiesArray[i]->getPoints();
				enemiesArray.erase(enemiesArray.begin() + i);
				i--;
			}
			else {
				ret = - 1.0 * enemiesArray[i]->getDamage();
			}
		}

		for (int i = 0; i < sharksArray.size(); i++) {
			if (sharksArray[i]->getBounds().intersects(playerBounds)) {
				if (sharksArray[i]->getSize() <= playerSize) {
					ret = sharksArray[i]->getPoints();
					sharksArray.erase(sharksArray.begin() + i);
					i--;
				}
				else {
					ret = -1.0 * sharksArray[i]->getDamage();
				}
			}
		}
	}

	for (int i = 0; i < floatingArray.size(); i++) {
		if (floatingArray[i]->getBounds().intersects(playerBounds)) {
			if (floatingArray[i]->getSize() <= playerSize) {
				ret = floatingArray[i]->getPoints();
				floatingArray.erase(floatingArray.begin() + i);
				i--;
			}
			else {
				ret = -1.0 * floatingArray[i]->getDamage();
			}
		}
	}
	
	return ret;
}
