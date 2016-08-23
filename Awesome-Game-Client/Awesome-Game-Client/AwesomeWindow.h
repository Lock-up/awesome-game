#pragma once

#define BorderWidth 4
#define ControlBarHeight 28
#define ControlBarMargin 4
#define ControlMargin 12

class AwesomeWindow
{
public:
	AwesomeWindow(sf::RenderWindow* window, float width, float height);
	~AwesomeWindow();
	void Render();

private:
	sf::RenderWindow* _window;
	float _width;
	float _height;
};
