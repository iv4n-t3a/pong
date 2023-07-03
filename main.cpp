#include <iostream>
#include <string.h>

#include "ui.h"


int main(int argc, char *argv[]) {
	sf::RenderWindow win(sf::VideoMode(800, 800), "PONG");
	Field f;

	UI ui(win, f);
	ui.run();
	return 0;
}
