#include "stdafx.h"
#include "Windowmanager.h"

using namespace sf;

void Windowmanager::CreateWindow() {
	RectangleShape shape(Vector2f{ 200.f, 120.f });
	shape.setFillColor(Color::Blue);

	_window->draw(shape);
	_window->display();
}
