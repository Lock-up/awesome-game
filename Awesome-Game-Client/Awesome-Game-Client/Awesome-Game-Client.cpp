// Awesome-Game-Client.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Windowmanager.h"

int main()
{
	sf::VideoMode mode;
	sf::RenderWindow window(mode.getFullscreenModes()[1], "SFML works!");
	//render_window.setFramerateLimit(60);

	tgui::Gui gui{ window };
	
	tgui::Button::Ptr button = std::make_shared<tgui::Button>();
	button->setText("Asdf");
	gui.add(button);

	tgui::ChildWindow::Ptr c_window = std::make_shared<tgui::ChildWindow>();
	c_window->keepInParent(true);
	c_window->setResizable(true);
	c_window->setTitleButtons((tgui::ChildWindow::TitleButtons)(tgui::ChildWindow::TitleButtons::Minimize | tgui::ChildWindow::TitleButtons::Close));
	gui.add(c_window);

	// Init window manager
	/*Windowmanager::instance().Init(&render_window);
	render_window.display();*/


	sf::Event event;
	sf::Clock clock;

	while (window.isOpen())
	{
		//window.clear(sf::Color::Black);

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
					Windowmanager::instance().CreateWindow();
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					//Windowmanager::instance().CreateWindow();
				}
			}
		}

		window.clear();
		gui.draw();
		window.display();
		
		//Windowmanager::instance().RedrawWindows();

		//window.display();
	}

	return 0;
}
