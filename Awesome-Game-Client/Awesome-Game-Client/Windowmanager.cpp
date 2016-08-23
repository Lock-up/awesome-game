#include "stdafx.h"
#include "Windowmanager.h"

using namespace sf;

void Windowmanager::MouseClick(float x, float y, sf::Mouse::Button button) {

}

void Windowmanager::CreateWindow(float width, float height) {
	AwesomeWindow* w = new AwesomeWindow(_window, width, height);
	w->Render();
	_windows.push_back(w);
}
