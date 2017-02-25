#include "stdafx.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
    : mWindow(sf::VideoMode(1024, 768), "World", sf::Style::Close)
{
    //sf::VideoMode mode;
    //mWindow = sf::RenderWindow(mode.getFullscreenModes()[1], "SFML works!");
    ResourceHolder<sf::Image, Textures::ID>::instance().init();

    //tgui::Gui mGui{ mWindow };

    mGui = new tgui::Gui();
    mGui->setWindow(mWindow);

    mMenu = new Menu_Main(*mGui);

    mMenu->LoadWidgets();
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            update(TimePerFrame);

        }

        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (mGui->handleEvent(event))
        {
            // Todo: Bubble event ?
            continue;
        }

        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;

        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;

        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time elapsedTime)
{
    // handle world updates here
}

void Game::render()
{
    mWindow.clear();

    // draw world here

    mGui->draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch (key)
    {
    case sf::Keyboard::Key::Add:
    case sf::Keyboard::Key::Equal:
    {
        std::cout << "Handle zoom in" << std::endl;
    }break;
    case sf::Keyboard::Key::Subtract:
    case sf::Keyboard::Key::Dash:
    {
        std::cout << "Handle zoom out" << std::endl;
    }break;
    default:
    {
        std::cout << "Key '" << key << "' was pressed but has no function!" << std::endl;
    }
    }
}
