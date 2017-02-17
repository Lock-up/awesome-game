// Awesome-Game-Client.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include "Menu\Menu_Main.hpp"

int main()
{
#ifndef _DEBUG
	//Start the SFML display window
	sf::RenderWindow Splash(sf::VideoMode(1024, 768, 32), "", sf::Style::None);
	Splash.setMouseCursorVisible(false);

	//Load the images for each individual screen (only one for now)
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets/splash.png"))
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
