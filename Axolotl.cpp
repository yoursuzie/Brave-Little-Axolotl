#include "Axolotl.h"

Axolotl::Axolotl(float aSize, int aSpeed, int aHealth)
{
	size = aSize;
	speed = aSpeed;
	health = aHealth;
	state = IDLE;
	phase = 0;
	animationSpeed = 4;
	score = 0;
	rectX = 22;
	rectY = 28;

	idle.loadFromFile("assets/Axolotl_Blue_Floating_Idle.png");
	swimming.loadFromFile("assets/Axolotl_Blue_Swimming.png");
	idletoswim.loadFromFile("assets/Axolotl_Blue_Preparing_To_Swim.png");
	swimtoidle.loadFromFile("assets/Axolotl_Blue_Preparing_To_Idle.png");
	hurtSwimming.loadFromFile("assets/Axolotl_Blue_Hurt1.png");
	hurtIdle.loadFromFile("assets/Axolotl_Blue_Hurt2.png");
	dying.loadFromFile("assets/Axolotl_Blue_Dying.png");
	preparingToSleep.loadFromFile("assets/Axolotl_Blue_Preparing_To_Sleep.png");
	sleeping.loadFromFile("assets/Axolotl_Blue_Sleeping.png");
	shieldTxt.loadFromFile("assets/Bubble.png");


	axolotl.setTexture(idle);
	bubbleShield.setTexture(shieldTxt);
	axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
	axolotl.setOrigin(axolotl.getLocalBounds().width/2, axolotl.getLocalBounds().height/2);
	maxPhase = animationSpeed * 7;
	axolotl.setScale(size, size);
	bubbleShield.setOrigin(bubbleShield.getLocalBounds().width / 2, bubbleShield.getLocalBounds().height / 2);

	changingToIdle = false;
	changingToSwim = false;
	hasShield = false;
	isHurt = false;
}

void Axolotl::move(sf::Vector2f aPos)
{
	sf::Vector2f move = aPos - axolotl.getPosition();
	if (sqrt(abs(move.x) + abs(move.y)) >= speed) {
		if (state != SWIMMING && state != HURTIDLE && state != HURTSWIMMING && state != DYING && state != FALLINGASLEEP && state != SLEEPING && !changingToSwim) {
			state = IDLETOSWIM;
			shieldMovement = shieldMovement + sf::Vector2f(0, -1 * 8 * size);
			axolotl.setTexture(idletoswim);
			rectX = 32;
			rectY = 28;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			maxPhase = animationSpeed * 8;
			phase = 0;
			changingToSwim = true;
		}
		float prop = move.x / move.y;
		int sgnX = 1, sgnY = 1;
		if (move.x < 0) sgnX = -1;
		if (move.y < 0) sgnY = -1;
		axolotl.setScale(-1 * sgnX * size, size);
		move.x = sgnX * sqrt(pow(speed, 2) / (1 + 1 / pow(prop, 2)));
		move.y = sgnY * sqrt(pow(speed, 2) / (1 + pow(prop, 2)));
		axolotl.move(move);
		bubbleShield.move(move);
	}
	else {
		if (state != IDLE && state != HURTIDLE && state != HURTSWIMMING && state != DYING && state != FALLINGASLEEP && state != SLEEPING && !changingToIdle) {
			state = SWIMTOIDLE;
			shieldMovement = shieldMovement + sf::Vector2f(0, 8 * size);
			axolotl.setTexture(swimtoidle);
			rectX = 32;
			rectY = 28;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			maxPhase = animationSpeed * 8;
			phase = 0;
			changingToIdle = true;
		}
	}
	if (sqrt(pow(shieldMovement.x, 2) + pow(shieldMovement.y, 2)) > 0) {

		sf::Vector2f movement = shieldMovement;
		float prop = movement.x / movement.y;
		int sgnX = 1, sgnY = 1;
		if (movement.x < 0) sgnX = -1;
		if (movement.y < 0) sgnY = -1;
		movement.x = sgnX * sqrt(pow(speed/4, 2) / (1 + 1 / pow(prop, 2)));
		movement.y = sgnY * sqrt(pow(speed/4, 2) / (1 + pow(prop, 2)));
		bubbleShield.move(movement);

		if (sqrt(pow(shieldMovement.x, 2) + pow(shieldMovement.y, 2)) <= sqrt(pow(movement.x, 2) + pow(movement.y, 2))) {
			shieldMovement = sf::Vector2f(0, 0);
		}
		else {
			shieldMovement -= movement;
		}
	}
	
}

void Axolotl::drawOnWindow(sf::RenderWindow& window)
{
	phase++;

	if (health <= 0 && state != DYING) {
		
		axolotl.setTexture(dying);
		rectX = 32;
		rectY = 32;
		axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
		maxPhase = animationSpeed * 11;
		phase = 0;
		state = DYING;
	}

	if (isHurt) {
		if (state == SWIMMING) {
			axolotl.setTexture(hurtSwimming);
			rectX = 32;
			rectY = 12;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			maxPhase = animationSpeed * 4;
			phase = 0;
			state = HURTSWIMMING;
		}
		else if (state == IDLE) {
			axolotl.setTexture(hurtIdle);
			rectX = 20;
			rectY = 28;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			maxPhase = animationSpeed * 4;
			phase = 0;
			state = HURTIDLE;
		}
		isHurt = false;
	}


	if (phase > maxPhase) {
		if (state == FALLINGASLEEP) {
			state = SLEEPING;
			axolotl.setTexture(sleeping);
			rectX = 32;
			rectY = 32;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			animationSpeed = 50;
			maxPhase = animationSpeed * 2;
			phase = 0;
		}
		if (state == HURTSWIMMING || state == IDLETOSWIM) {
			state = SWIMMING;
			axolotl.setTexture(swimming);
			rectX = 31;
			rectY = 12;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			maxPhase = animationSpeed * 11;
			phase = 0;
			changingToSwim = false;
			changingToIdle = false;
		}
		else if (state == HURTIDLE || state == SWIMTOIDLE) {
			state = IDLE;
			axolotl.setTexture(idle);
			rectX = 32;
			rectY = 30;
			axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
			maxPhase = animationSpeed * 7;
			phase = 0;
			changingToSwim = false;
			changingToIdle = false;
		}
		else if (state == DYING) {
			phase = maxPhase;
		}
		else {
			phase = 0;
		}
	}
	int op = phase / animationSpeed;
	if (phase % animationSpeed == 0) 
	{
		axolotl.setTextureRect(sf::IntRect(rectX * op, 0, rectX, rectY));
	}

	window.draw(axolotl);

	
	if (hasShield == true) {
		float scaleX = (rectX*size + 10) / shieldTxt.getSize().x;
		float scaleY = (rectY*size + 10) / shieldTxt.getSize().y;
		if (scaleX > scaleY) {
			bubbleShield.setScale(scaleX + 1.25, scaleX + 1.25);
		}
		else {
			bubbleShield.setScale(scaleY + 1.25, scaleY + 1.25);

		}

		
		window.draw(bubbleShield);

	}
}

void Axolotl::setPosition(sf::Vector2f aPos)
{
	axolotl.setPosition(aPos);
}

void Axolotl::setPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Axolotl::getPosition() const
{
	return axolotl.getPosition();
}

int Axolotl::getSpeed() const
{
	return speed;
}

sf::FloatRect Axolotl::getBounds() const
{
	return axolotl.getGlobalBounds();
}

void Axolotl::hit(int aDamage)
{
	if (hasShield == false) 
	{
		health -= aDamage;
		if (aDamage > 0) {
			isHurt = true;
		}
	}
}

int Axolotl::getHealth() const
{
	return health;
}

float Axolotl::getSize() const
{
	return size;
}

void Axolotl::addPoints(float aPoints)
{
	score += aPoints;
	size += aPoints/100;
}

void Axolotl::heal()
{
	if (health < 8) health++;
}

void Axolotl::toggleShield(bool aHasShield)
{
	if (aHasShield == false) {
		hasShield = false;
	}
	else if (hasShield == false) {
		hasShield = aHasShield;
		bubbleShield.setPosition(axolotl.getPosition());
		if (hasShield && (state == SWIMMING || state == IDLETOSWIM)) {
			shieldMovement = sf::Vector2f(0, -1 * 8 * size);
		}
		if (hasShield && (state == IDLE || state == SWIMTOIDLE)) {
			shieldMovement = sf::Vector2f(0, 8 * size);
		}
	}
}

bool Axolotl::shieldDeployed()
{
	return hasShield;
}

void Axolotl::goToSleep()
{
	state = FALLINGASLEEP;
	axolotl.setTexture(preparingToSleep);
	rectX = 32;
	rectY = 32;
	axolotl.setTextureRect(sf::IntRect(0, 0, rectX, rectY));
	maxPhase = animationSpeed * 15;
	phase = 0;
}

void Axolotl::moveToBottom() {
	sf::Vector2f bottomLeft = sf::Vector2f(axolotl.getGlobalBounds().left, axolotl.getGlobalBounds().top + axolotl.getGlobalBounds().height);
	sf::Vector2f target = sf::Vector2f(bottomLeft.x, 1080);
	sf::Vector2f movement = target - bottomLeft;
	if (sqrt(pow(movement.x, 2) + pow(movement.y, 2)) > speed) {
		float prop = movement.x / movement.y;
		int sgnX = 1, sgnY = 1;
		if (movement.x < 0) sgnX = -1;
		if (movement.y < 0) sgnY = -1;
		movement.x = sgnX * sqrt(pow(speed, 2) / (1 + 1 / pow(prop, 2)));
		movement.y = sgnY * sqrt(pow(speed, 2) / (1 + pow(prop, 2)));
	}
	axolotl.move(movement);
	
}


