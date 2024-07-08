#include "Axolotl.h";
#include "AxolotlController.h"


int main()
{
	srand(time(nullptr)); //przypisujemy ziarno

	// Początkowe statystyki postaci:
	const int health = 8;
	const int speed = 5;
	const float size = 3;
	

	Axolotl ax(size, speed, health);
	AxolotlController ctrl(ax);
	ctrl.play();
	

}
