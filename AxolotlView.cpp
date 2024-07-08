#include "AxolotlView.h"

AxolotlView::AxolotlView(Axolotl& aAxolotl, sf::RenderWindow& aWindow, sf::View& aCamera, EnemyArray& aArray, PowerUps &aPowerUp) : axolotl(aAxolotl), window(aWindow), camera(aCamera), array(aArray), powerUp(aPowerUp)
{
	backgroundTxt.loadFromFile("assets/bckgr.png");
	background.setTexture(backgroundTxt);
	font.loadFromFile("assets/CorneroftheSky.ttf");
	bbyBlue = sf::Color(161, 202, 241);
	blackOut.loadFromFile("assets/Blackout.png");
	endScreen.setTexture(blackOut);
	endScreen.setOrigin(endScreen.getLocalBounds().width / 2, endScreen.getLocalBounds().height / 2);
	
	axolotlDead = false;

	defeat.setFont(font);
	defeat.setCharacterSize(90);
	defeat.setOutlineColor(sf::Color::Black);
	defeat.setOutlineThickness(3);
	defeat.setString("YOU DIED");
	defeat.setOrigin(defeat.getLocalBounds().width / 2, defeat.getLocalBounds().height / 2);

	win.setFont(font);
	win.setCharacterSize(90);
	win.setOutlineColor(sf::Color::Black);
	win.setOutlineThickness(3);
	win.setString("YOU WON");
	win.setOrigin(win.getLocalBounds().width / 2, defeat.getLocalBounds().height / 2);

	explanation.setFont(font);
	explanation.setCharacterSize(40);
	explanation.setOutlineColor(sf::Color::Black);
	explanation.setOutlineThickness(3);
	explanation.setString("Axolotl ate so much that it went for a nap");
	explanation.setOrigin(explanation.getLocalBounds().width / 2, explanation.getLocalBounds().height / 2);
}

void AxolotlView::setAxolotlDead(bool op) {
	axolotlDead = op;
}

void AxolotlView::setAxolotlSleep(bool op) {
	axolotlSleeping = op;
}

void AxolotlView::display()
{
	hb.setPosition(camera.getCenter() + sf::Vector2f{camera.getSize().x / 2, -camera.getSize().y / 2});
	window.clear(sf::Color::Black);
	window.setView(camera);
	window.draw(background);
	powerUp.draw(window);
	array.drawAll(window);
	axolotl.drawOnWindow(window);
	if (axolotlDead) {
		endScreen.setPosition(camera.getCenter());
		defeat.setPosition(camera.getCenter().x, window.getSize().y / 2 - 90);
		window.draw(endScreen);
		window.draw(defeat);
	}
	else if (axolotlSleeping) {
		
		win.setPosition(camera.getCenter().x, window.getSize().y / 2 - 90);
		explanation.setPosition(win.getPosition() + sf::Vector2f{ 0, 120 });
		window.draw(win);
		window.draw(explanation);

	}
	else {
		hb.draw(window, axolotl.getHealth());
	}
	window.display();
}

void AxolotlView::pauseScreen()
{

	sf::Text exit;
	sf::Text resume;
	sf::Text pause;

	exit.setFont(font);
	resume.setFont(font);
	pause.setFont(font);

	exit.setCharacterSize(70);
	resume.setCharacterSize(70);
	pause.setCharacterSize(90);

	exit.setOutlineColor(sf::Color::Black);
	resume.setOutlineColor(sf::Color::Black);
	pause.setOutlineColor(sf::Color::Black);

	exit.setOutlineThickness(3);
	resume.setOutlineThickness(3);
	pause.setOutlineThickness(3);

	exit.setString("EXIT");
	resume.setString("RESUME");
	pause.setString("PAUSED");

	exit.setOrigin(exit.getLocalBounds().width / 2, exit.getLocalBounds().height / 2);
	resume.setOrigin(resume.getLocalBounds().width / 2, resume.getLocalBounds().height / 2);
	pause.setOrigin(pause.getLocalBounds().width / 2, pause.getLocalBounds().height / 2);

	pause.setPosition(camera.getCenter().x, window.getSize().y / 2 - 90);
	resume.setPosition(pause.getPosition() + sf::Vector2f{0, 120});
	exit.setPosition(resume.getPosition() + sf::Vector2f{ 0, 80 });

	sf::Event event;
	sf::Vector2f mousePos;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseMoved) {
				mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				if (resume.getGlobalBounds().contains(mousePos)) {
					resume.setOutlineColor(bbyBlue);
					resume.setOutlineThickness(5);
				}
				else {
					resume.setOutlineColor(sf::Color::Black);
					resume.setOutlineThickness(3);

				}
				if (exit.getGlobalBounds().contains(mousePos)) {
					exit.setOutlineColor(bbyBlue);
					exit.setOutlineThickness(5);
				}
				else {
					exit.setOutlineColor(sf::Color::Black);
					exit.setOutlineThickness(3);
				}
			}
		}



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (resume.getGlobalBounds().contains(mousePos)) {
				return;
			}
			if (exit.getGlobalBounds().contains(mousePos)) {
				window.close();
			}
		}


		window.clear(sf::Color::Black);
		window.setView(camera);
		window.draw(background);
		powerUp.draw(window);
		array.drawAll(window);
		axolotl.drawOnWindow(window);
		window.draw(pause);
		window.draw(resume);
		window.draw(exit);
		window.display();


	}

}

void AxolotlView::startScreen()
{
	sf::Text title;
	sf::Text start;
	sf::Text exit;

	title.setFont(font);
	start.setFont(font);
	exit.setFont(font);

	title.setCharacterSize(110);
	start.setCharacterSize(70);
	exit.setCharacterSize(70);

	title.setOutlineColor(sf::Color::Black);
	start.setOutlineColor(sf::Color::Black);
	exit.setOutlineColor(sf::Color::Black);

	title.setOutlineThickness(3);
	start.setOutlineThickness(3);
	exit.setOutlineThickness(3);

	title.setString("The brave, little axolotl");
	start.setString("START");
	exit.setString("EXIT");

	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
	start.setOrigin(start.getLocalBounds().width / 2, start.getLocalBounds().height / 2);
	exit.setOrigin(exit.getLocalBounds().width / 2, exit.getLocalBounds().height / 2);

	title.setPosition(window.getSize().x * 0.75 + window.getSize().x / 2, window.getSize().y/2 - 310);
	start.setPosition(title.getPosition() + sf::Vector2f{0, 310});
	exit.setPosition(start.getPosition() + sf::Vector2f{ 0,80 });

	sf::Event event;
	sf::Vector2f mousePos;
	int axolotlTurn = 1000;

	while (window.isOpen()) {
		if(camera.getCenter().x + window.getSize().x/2 < axolotl.getPosition().x - 100) axolotlTurn = -1000;
		if (camera.getCenter().x - window.getSize().x/2 > axolotl.getPosition().x - 100) axolotlTurn = 1000;
		axolotl.move(axolotl.getPosition()+sf::Vector2f(axolotlTurn, 0));

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();

			if (event.type == sf::Event::MouseMoved) {
				mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)) + sf::Vector2f{static_cast<float>(0.75 * window.getSize().x), 0};
				if (start.getGlobalBounds().contains(mousePos)) {
					start.setOutlineColor(bbyBlue);
					start.setOutlineThickness(5);
				}
				else {
					start.setOutlineColor(sf::Color::Black);
					start.setOutlineThickness(3);
				}
				if (exit.getGlobalBounds().contains(mousePos)) {
					exit.setOutlineColor(bbyBlue);
					exit.setOutlineThickness(5);
				}
				else {
					exit.setOutlineColor(sf::Color::Black);
					exit.setOutlineThickness(3);
				}
			}
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (start.getGlobalBounds().contains(mousePos)) {
				return;
			}
			if (exit.getGlobalBounds().contains(mousePos)) {
				window.close();
			}
		}

		window.clear();
		window.setView(camera);
		window.draw(background);
		axolotl.drawOnWindow(window);
		window.draw(title);
		window.draw(start);
		window.draw(exit);
		window.display();
	}

}

