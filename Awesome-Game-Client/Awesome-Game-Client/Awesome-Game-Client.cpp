// Awesome-Game-Client.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

int main()
{
#ifndef _DEBUG
	//Start the SFML display window
	sf::RenderWindow Splash(sf::VideoMode(1024, 768, 32), "", sf::Style::None);
	Splash.setMouseCursorVisible(false);

	//Load the images for each individual screen (only one for now)
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets/images/splash.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	sf::Sprite OpenALSprite(texture);
	sf::Clock splash_clock;
	while (Splash.isOpen())
	{
		auto elapsedTime = splash_clock.getElapsedTime();
		if (elapsedTime.asSeconds() > 5)
		{
			Splash.close();
		}

		sf::Event event;
		while (Splash.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed) {
				Splash.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				// Escape key : exit
				if (event.key.code == sf::Keyboard::Escape)
					Splash.close();
			}

			Splash.clear();
			Splash.draw(OpenALSprite);
			Splash.display();
		}
	}
#endif // _DEBUG

	sf::VideoMode mode;
	sf::RenderWindow window(mode.getFullscreenModes()[1], "SFML works!");
	//render_window.setFramerateLimit(60);

	tgui::Gui gui{ window };

	// Load main menu
	auto menu = Menu_Main(gui);
	menu.LoadWidgets();
	
	/*tgui::Button::Ptr button = std::make_shared<tgui::Button>();
	button->setText("Asdf");
	gui.add(button);*/

	/*tgui::ChildWindow::Ptr c_window = std::make_shared<tgui::ChildWindow>();
	c_window->keepInParent(true);
	c_window->setResizable(true);
	c_window->setTitleButtons((tgui::ChildWindow::TitleButtons)(tgui::ChildWindow::TitleButtons::Minimize | tgui::ChildWindow::TitleButtons::Close));
	gui.add(c_window);*/
	
    // Try to load resources
    ResourceHolder<sf::Image, Textures::ID>::instance().init();

    //ResourceHolder<sf::Image, Textures::ID> rhImages;
    //try
    //{
    //    rhImages.load(Textures::DESERT_01, "Assets/Textures/DESERT_01.png");
    //    rhImages.load(Textures::GREENLAND_01, "Assets/Textures/GREENLAND_01.png");
    //    rhImages.load(Textures::SNOW_01, "Assets/Textures/SNOW_01.png");
    //}
    //catch (std::runtime_error& e)
    //{
    //    std::cout << "Exception: " << e.what() << std::endl;
    //    //assert(e.what() == NULL);
    //    return 1;
    //}

    //ResourceHolder<sf::Texture, Buildings::ID> rhBuildings;
    //try
    //{
    //    rhBuildings.load(Buildings::BLD_LUMBERJACK, "Assets/Buildings/bld_lumberjack.png");
    //}
    //catch (std::runtime_error& e)
    //{
    //    std::cout << "Exception: " << e.what() << std::endl;
    //    //assert(e.what() == NULL);
    //    return 1;
    //}

    CMap *map = new CMap(16, 16, Textures::DESERT_01);
    //map->getMapPlayerInfo()->pushPlayer(12, 34);
    //map->getMapPlayerInfo()->pushPlayer(56, 78);
    //map->saveMapWithFilename("SpikesMap_BIGAF");
    //CMap *map2 = new CMap("SpikesMap_BIGAF", rhImages);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (gui.handleEvent(event))
			{
				// Todo: Bubble event ?
				continue;
			}

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseLeft) {
				// Todo: Make something awesome here
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Key::W) {
					
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					
				}
			}
		}

		window.clear();
		gui.draw();
		window.display();
	}

	return 0;
}
