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

    map->getMapPlayerInfo()->createPlayerMarkerPixels(*map->getMapInfo());

    sf::Texture tex;
    tex.create(map->getMapInfo()->getMapSizeX(),map->getMapInfo()->getMapSizeY());

    sf::Uint8* pPix = map->getPixels();

    tex.update(pPix);

    sf::Sprite spr;
    spr.scale(16.f, 16.f);
    spr.setTexture(tex);

    sf::Texture tex2;
    tex2.create(map->getMapInfo()->getMapSizeX(), map->getMapInfo()->getMapSizeY());

    sf::Uint8* pPix2 = map->getMapPlayerInfo()->getPlayerMarker();

    tex2.update(pPix2);

    sf::Sprite spr2;
    spr2.scale(16.f, 16.f);
    spr2.setTexture(tex2);

	//sf::VideoMode mode;
	//sf::RenderWindow window(mode.getFullscreenModes()[1], "SFML works!");
    sf::RenderWindow window(sf::VideoMode(320, 240), "Awesome-World-Editor!");

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
                else if (event.key.code == sf::Keyboard::Key::Add || event.key.code == sf::Keyboard::Key::Equal)
                {
                    spr.scale(2.f, 2.f);
                    spr2.scale(2.f, 2.f);

                    std::cout << "Scale up to: " << spr.getScale().x << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Key::Subtract || event.key.code == sf::Keyboard::Key::Dash)
                {
                    spr.scale(0.5f, 0.5f);
                    spr2.scale(0.5f, 0.5f);
                    std::cout << "Scale down to: " << spr.getScale().x << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Key::P)
                {
                    map->toggleShowPlayers();
                }
                else
                {
                    std::cout << "Key '" << event.key.code << "' was pressed but has no function!" << std::endl;
                }
			}
		}

		window.clear();
		//window.draw(shape);
        window.draw(spr);
        if (map->getShowPlayers())
            window.draw(spr2);

		window.display();
	}

	return 0;
}
