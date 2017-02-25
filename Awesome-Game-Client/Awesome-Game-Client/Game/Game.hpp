#ifndef GAME_HPP
#define GAME_HPP

#include "stdafx.h"


class Game : private sf::NonCopyable
{
public:
    Game();
    void                    run();


private:
    void                    processEvents();
    void                    update(sf::Time elapsedTime);
    void                    render();

    void                    handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
    static const sf::Time   TimePerFrame;

    sf::RenderWindow        mWindow;
    tgui::Gui               *mGui;
    Menu_Main               *mMenu;
};

#endif // GAME_HPP
