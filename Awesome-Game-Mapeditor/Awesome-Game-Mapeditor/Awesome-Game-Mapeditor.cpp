// Awesome-Game-Mapeditor.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
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

    //sf::Texture tmpTest(textures.get(Textures::GREENLAND_01));
    //sf::Image tmpImage = tmpTest.copyToImage();
    //for (int i = 0; i < 32; i++)
    //{
    //    for (int j = 0; j < 32; j++)
    //    {
    //        if (std::rand() % 2)
    //            tmpImage.setPixel(i, j, sf::Color(0, 0, 0, 0));
    //    }
    //}
    //tmpTest.loadFromImage(tmpImage);

    //sf::Sprite desert(textures.get(Textures::DESERT_01));
    //sf::Sprite greenland(textures.get(Textures::GREENLAND_01));
    //sf::Sprite snow(textures.get(Textures::SNOW_01));
    //greenland.setPosition(128.f, 128.f);
    //snow.setPosition(256.f, 256.f);
    //desert.setPosition(0.f, 0.f);

    //sf::Sprite transgreen(tmpTest);
    //transgreen.setPosition(0.f, 0.f);

    //greenland.scale(4.f, 4.f);
    //snow.scale(4.f, 4.f);
    //desert.scale(4.f, 4.f);
    //transgreen.scale(4.f, 4.f);

    CMap *map = new CMap(2, 2, rhImages);
    std::cout << "Chunks in Container: " << map->getCAwesomeChunkContainer()->getChunkCount() << std::endl;

    //map->generateImage(rhImages);

    //sf::Texture texture;
    //texture.loadFromImage(map->getImage());
    //sf::Sprite mapTextured(texture);


    sf::Texture texture2 = map->getCAwesomeChunkContainer()->getChunk(0)->getTexture();
    sf::Sprite chunk(texture2);
    chunk.setPosition(256.f, 256.f);

    /*
    // Not working:
    sf::Sprite chunk(map->getCAwesomeChunkContainer()->getChunk(0)->getTexture());
    chunk.setPosition(256.f, 256.f);

    // Working:
    sf::Texture texture2 = map->getCAwesomeChunkContainer()->getChunk(0)->getTexture();
    sf::Sprite chunk(texture2);
    chunk.setPosition(256.f, 256.f);

    */

    sf::Texture tex3;
    map->getCAwesomeChunkContainer()->getChunk(0)->getTexture(tex3);
    sf::Sprite chunk2(tex3);
    chunk2.setPosition(288.f, 288.f);


    //mapTextured.scale(4.f, 4.f);

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
                }
                else if (event.key.code == sf::Keyboard::Key::Subtract || event.key.code == sf::Keyboard::Key::Dash)
                {
                    std::cout << "Scale down" << std::endl;
                    //mapTextured.scale(0.5f, 0.5f);
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

        // Is this also working? -> Nope, gives white square problem
        window.draw(chunk);

        // Okay, this is working as well
        window.draw(chunk2);

		window.display();
	}

	return 0;
}
