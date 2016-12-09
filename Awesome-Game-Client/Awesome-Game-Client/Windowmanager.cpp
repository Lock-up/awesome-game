#include "stdafx.h"
#include "Windowmanager.h"

using namespace sf;

void Windowmanager::MouseClick(float x, float y, sf::Mouse::Button button) {

}

void Windowmanager::CreateWindow(float width, float height, float left, float top) {
	float newLeft = left;
	float newTop = top;

	if (newLeft == -1) {
		// get the most right window
		for (std::vector<int>::size_type i = 0; i != _windows.size(); i++) {
			float leftCmp = _windows[i]->GetLeft();
			if (leftCmp > newLeft) {
				newLeft = leftCmp;
			}
		}

		newLeft += 12;

		if ((newLeft + width) > _window->getSize().x) {
			// Todo Reset 
			newLeft = 4;
		}

	}
	if (newTop == -1) {
		// get the most right window
		for (std::vector<int>::size_type i = 0; i != _windows.size(); i++) {
			float topCmp = _windows[i]->GetTop();
			if (topCmp > newTop) {
				newTop = topCmp;
			}
		}

		newTop += 12;

		if ((newTop + height) > _window->getSize().y) {
			// Todo Reset 
			newTop = 4;
		}
	}

	AwesomeWindow* w = new AwesomeWindow(_window, width, height, newLeft, newTop);
	w->Render();
	_windows.push_back(w);
}

void Windowmanager::RedrawWindows() {
	/*for (std::vector<int>::size_type i = 0; i != _windows.size(); i++) {
		_windows[i]->Render();
	}*/

	for (std::vector<int>::size_type i = _windows.size() - 1;
		i != (std::vector<int>::size_type) - 1; i--) {
		_windows[i]->Render();
	}
}
