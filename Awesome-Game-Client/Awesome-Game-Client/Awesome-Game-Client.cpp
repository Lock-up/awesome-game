// Awesome-Game-Client.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Windowmanager.h"

sf::CircleShape shape(10.f);

int main()
{
	sf::VideoMode mode;
	sf::RenderWindow window(mode.getFullscreenModes()[1], "SFML works!");

	window.setFramerateLimit(60);

	shape.setFillColor(sf::Color::Red);

	// Init window manager
	Windowmanager::instance().Init(&window);
	window.display();

	while (window.isOpen())
	{
		//window.clear(sf::Color::Black);

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
					Windowmanager::instance().CreateWindow();
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					Windowmanager::instance().CreateWindow();
				}
			}
		}


		//window.display();
	}

	return 0;
}
