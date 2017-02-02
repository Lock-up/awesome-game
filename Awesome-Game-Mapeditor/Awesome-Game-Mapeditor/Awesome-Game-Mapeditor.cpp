// Awesome-Game-Mapeditor.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

int main()
{   
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
    sf::RenderWindow window(sf::VideoMode(640, 480), "Awesome-World-Editor!");

	window.setFramerateLimit(10);

    // Try to load resources
    ResourceHolder<sf::Image, Textures::ID> rhImages;
    try
    {
        rhImages.load(Textures::DESERT_01, "Media/Textures/DESERT_01.png");
        rhImages.load(Textures::GREENLAND_01, "Media/Textures/GREENLAND_01.png");
        rhImages.load(Textures::SNOW_01, "Media/Textures/SNOW_01.png");
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }

    ResourceHolder<sf::Texture, Buildings::ID> rhBuildings;
    try
    {
        rhBuildings.load(Buildings::BLD_LUMBERJACK, "Media/Buildings/bld_lumberjack.png");
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }

    CMap *map = new CMap(2, 2, rhImages, Textures::DESERT_01);
    std::cout << "Chunks in Container: " << map->getCAwesomeChunkContainer()->getChunkCount() << std::endl;
    map->getMapInfo()->serialize();
    map->getMapPlayerInfo()->pushPlayer(13, 37);
    map->getMapPlayerInfo()->serialize();

    //map->generateImage(rhImages);

    sf::Sprite chunk(map->getChunkTexture(0));
    chunk.setPosition(0.f, 0.f);

    sf::Sprite bldlumber(rhBuildings.get(Buildings::BLD_LUMBERJACK));
    bldlumber.setPosition(5.f, 10.f);

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
                    std::cout << "Scale up" << std::endl;
                    //mapTextured.scale(2.0f, 2.0f);
                    bldlumber.scale(2.0f, 2.0f);
                    chunk.scale(2.0f, 2.0f);

                    
                    bldlumber.setPosition(bldlumber.getPosition().x * 2.f, bldlumber.getPosition().y * 2.f);
                }
                else if (event.key.code == sf::Keyboard::Key::Subtract || event.key.code == sf::Keyboard::Key::Dash)
                {
                    std::cout << "Scale down" << std::endl;
                    //mapTextured.scale(0.5f, 0.5f);
                    bldlumber.scale(0.5f, 0.5f);
                    chunk.scale(0.5f, 0.5f);

                    bldlumber.setPosition(bldlumber.getPosition().x * 0.5f, bldlumber.getPosition().y * 0.5f);
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

        // Wow, this works, I'm amazed
        //window.draw(mapTextured);

        window.draw(chunk);

        // Buildings?
        window.draw(bldlumber);

		window.display();
	}

	return 0;
}
