// Awesome-Game-Mapeditor.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

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


	//sf::VideoMode mode;
	//sf::RenderWindow window(mode.getFullscreenModes()[1], "SFML works!");
    sf::RenderWindow window(sf::VideoMode(320, 240), "Awesome-World-Editor!");

	window.setFramerateLimit(10);

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
				if (event.key.code == sf::Keyboard::Key::W) 
                {
				}
				else if (event.key.code == sf::Keyboard::Key::A) 
                {

				}
				else if (event.key.code == sf::Keyboard::Key::S) 
                {

				}
				else if (event.key.code == sf::Keyboard::Key::D) 
                {

				}
                else if (event.key.code == sf::Keyboard::Key::Add || event.key.code == sf::Keyboard::Key::Equal)
                {

                }
                else if (event.key.code == sf::Keyboard::Key::Subtract || event.key.code == sf::Keyboard::Key::Dash)
                {

                }
                else if (event.key.code == sf::Keyboard::Key::P)
                {

                }
                else
                {
                    std::cout << "Key '" << event.key.code << "' was pressed but has no function!" << std::endl;
                }
			}
		}

		window.clear();

		window.display();
	}

	return 0;
}
