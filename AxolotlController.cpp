#include "AxolotlController.h"

void AxolotlController::update()
{
	if (!changeSFX && array.isSharkChasing()){
		sound.playChase();
		changeSFX = true;
	}
	else if (changeSFX && !array.isSharkChasing()) {
		sound.playBGM();
		changeSFX = false;
	}

	if (axolotl.getSize() > 9) {
		doSpawnFish = false;
		if (array.isEmpty() && !win) {
			win = true;
			axolotl.goToSleep();
			
		}
	}

	float collision = 0;
	if (axolotl.getHealth() > 0 && !win) {
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		axolotl.move(mousePos);
		collision = array.checkCollision(axolotl.getBounds(), axolotl.getSize());
	}
	if (axolotl.getPosition().x > camera.getSize().x / 2 && axolotl.getPosition().x < window.getSize().x * 2.5 - camera.getSize().x / 2) {
		camera.setCenter(axolotl.getPosition().x, window.getSize().y / 2);
	}
	if (collision > 0) {
		axolotl.addPoints(multiplier * collision);
		sound.playEat();
		cooldown = clock();
	}
	if (float(clock() - cooldown) >= 2000) {
		if (collision < 0) {
			axolotl.hit(abs(collision));
			if(!axolotl.shieldDeployed()) sound.playHit();
			cooldown = clock();
		}
	}
	if(doSpawnFish) array.spawn();

	array.moveAll(axolotl.getPosition());

	if (multiplier != 1 && clock() - powerUpTime1 > 15000) {
		multiplier = 1;
	}
	if (axolotl.shieldDeployed() == true && clock() - powerUpTime2 > 15000) {
		axolotl.toggleShield(false);
	}


	if (doSpawnFish) powerUp.spawn();

	int pow = powerUp.checkCollision(axolotl.getBounds());
	if (pow != 0) sound.playBubblePop();
	if (pow == 1) {
		axolotl.heal();
	}
	else if (pow == 2) {
		powerUpTime1 = clock();
		multiplier = 2;
	}
	else if (pow == 3) {
		powerUpTime2 = clock();
		axolotl.toggleShield(true);
	}
}

void AxolotlController::defeatScreen()
{
	array.axolotlDead();
	axolotl.moveToBottom();
	view.setAxolotlDead(true);

}

void AxolotlController::winScreen()
{
	axolotl.moveToBottom();
	view.setAxolotlSleep(true);
}

AxolotlController::AxolotlController(Axolotl& aAxolotl) : axolotl(aAxolotl), view(axolotl, window, camera, array, powerUp), array(30), window(sf::VideoMode(1920, 1080), "The brave, little axolotl", sf::Style::Fullscreen), camera(sf::FloatRect(0.75 * 1920, 0, 1920, 1080))
{
	sf::Image icon;
	icon.loadFromFile("assets/gameicon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	pointerTxt.loadFromFile("assets/pointer.png");
	pointer.loadFromPixels(pointerTxt.getPixelsPtr(), sf::Vector2u{ 18,18 }, sf::Vector2u{ 0,0 });
	window.setMouseCursor(pointer);

	cooldown = clock();
	multiplier = 1;

	powerUpTime1 = clock();
	powerUpTime2 = clock();

	doSpawnFish = true;
	win = false;
	changeSFX = false;
	dead = false;
	hasWon = false;
}

void AxolotlController::play()
{
	sound.playBGM();

	sf::Event event;
	axolotl.setPosition(camera.getCenter().x - window.getSize().x/2 - 200, 3 * window.getSize().y / 4);
	window.setFramerateLimit(30);
	view.startScreen();

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if ((axolotl.getHealth() <= 0 || win) && event.type == sf::Event::KeyPressed) window.close();
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				view.pauseScreen();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				
				axolotl.addPoints(600);
				axolotl.goToSleep();
				win = true;
			}
		}

		update();
		view.display();
		if (axolotl.getHealth() <= 0) {
			if (!dead) {
				sound.playDeath();
				dead = true;
			}
			defeatScreen();
		}
		if (win) {
			if (!hasWon) {
				sound.playLullaby();
				hasWon = true;
				
			}
			
			winScreen();
		}
	}


}
