#include "stdafx.h"
#include "AwesomeWindow.h"

using namespace sf;

AwesomeWindow::AwesomeWindow(sf::RenderWindow* window, float width, float height, float left, float top)
{
	_window = window;
	_width = width;
	_height = height;
	_left = left;
	_top = top;
}

void AwesomeWindow::Render()
{
	// TODO: 
	// - Generate position
	// - Add close, minimize, (maximize ?) controls
	// - Dragable
	// - z-Index

	// Border
	RectangleShape shape(Vector2f{ _width, _height });
	shape.setFillColor(Color::Color(0xee, 0xee, 0xee, 0xff));
	shape.setPosition(Vector2f{ _left, _top });

	// Content
	RectangleShape shape2(Vector2f{ _width - BorderWidth, _height - BorderWidth - ControlBarHeight });
	shape2.setFillColor(Color::Black);
	shape2.setPosition(Vector2f{ BorderWidth / 2 + _left, BorderWidth / 2 + ControlBarHeight + _top });

	// Controlbar controls
	// close control
	Font f;
	f.loadFromFile("Fonts\\arial.ttf");

	Text close(String("X"), f, 20);
	close.setColor(Color::Black);
	close.setPosition(Vector2f{ _left + _width - BorderWidth / 2 - ControlBarMargin - close.getGlobalBounds().width, ControlBarMargin + _top });

	// minimize control
	Text minimize(String("_"), f, 20);
	minimize.setColor(Color::Black);
	minimize.setPosition(Vector2f{ _left + _width - BorderWidth / 2 - ControlBarMargin - close.getGlobalBounds().width - ControlMargin - minimize.getGlobalBounds().width, _top });

	_window->draw(shape);
	_window->draw(shape2);
	_window->draw(close);
	_window->draw(minimize);

	// TODO: Render loop strategy
	// Clear and redraw if content change or window moves
	_window->display();
}

float AwesomeWindow::GetWidth() {
	return _width;
}

float AwesomeWindow::GetHeight() {
	return _height;
}

float AwesomeWindow::GetLeft() {
	return _left;
}

float AwesomeWindow::GetTop() {
	return _top;
}

AwesomeWindow::~AwesomeWindow()
{
}
