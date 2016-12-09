#pragma once

#define BorderWidth 4
#define ControlBarHeight 28
#define ControlBarMargin 4
#define ControlMargin 12

class AwesomeWindow
{
public:
	AwesomeWindow(sf::RenderWindow* window, float width, float height, float left = -1, float top = -1);
	~AwesomeWindow();
	void Render();

	float GetWidth();
	float GetHeight();
	float GetLeft();
	float GetTop();

private:
	sf::RenderWindow* _window;
	float _width;
	float _height;
	float _left;
	float _top;
};
