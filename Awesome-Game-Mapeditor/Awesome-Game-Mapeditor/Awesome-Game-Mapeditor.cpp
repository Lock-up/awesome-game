// Awesome-Game-Mapeditor.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

sf::CircleShape shape(10.f);

void up()
{
	for (int i = 0; i < 10; i++) {
		shape.move(0, -1);
		sf::sleep(sf::microseconds(1000));
	}
}
void left()
{
	for (int i = 0; i < 10; i++) {
		shape.move(-1, 0);
		sf::sleep(sf::microseconds(1000));
	}
}
void down()
{
	for (int i = 0; i < 10; i++) {
		shape.move(0, 1);
		sf::sleep(sf::microseconds(1000));
	}
}
void right()
{
	for (int i = 0; i < 10; i++) {
		shape.move(1, 0);
		sf::sleep(sf::microseconds(1000));
	}
}

int main()
{
    CMap *map = new CMap();
    
	// Code to find working directory
	//char cCurrentPath[FILENAME_MAX];
	//if (!_getcwd_dbg(cCurrentPath, sizeof(cCurrentPath), _NORMAL_BLOCK, NULL, NULL))
	//{
	//	return errno;
	//}
	//cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	//printf("The current working directory is %s\n", cCurrentPath);

    map->loadFromFile("Maps\\w1.awf");

    std::cout << "Version: " << map->getMapInfo()->getVersion() << std::endl;

    std::cout << "X: " << map->getMapInfo()->getMapSizeX() << " Y: " << map->getMapInfo()->getMapSizeY() << std::endl;

    std::cout << "Name: " << map->getMapInfo()->getMapName() << std::endl;

    std::cout << "Players: " << (int)map->getMapPlayerInfo()->getPlayerCount() << std::endl;

	//sf::VideoMode mode;
	//sf::RenderWindow window(mode.getFullscreenModes()[1], "SFML works!");
    sf::RenderWindow window(sf::VideoMode(320, 240), "SFML works!");

	window.setFramerateLimit(10);

	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseLeft) {
				// Todo: Make something awesome here
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Key::W) {
					sf::Thread thread(&up);
					thread.launch();
				}
				else if (event.key.code == sf::Keyboard::Key::A) {
					sf::Thread thread(&left);
					thread.launch();
				}
				else if (event.key.code == sf::Keyboard::Key::S) {
					sf::Thread thread(&down);
					thread.launch();
				}
				else if (event.key.code == sf::Keyboard::Key::D) {
					sf::Thread thread(&right);
					thread.launch();
				}
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
