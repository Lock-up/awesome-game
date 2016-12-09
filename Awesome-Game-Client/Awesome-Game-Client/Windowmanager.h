#pragma once
#include "AwesomeWindow.h"

class Windowmanager
{
public:
	

#pragma region Singleton

	static Windowmanager& instance()
	{
		static Windowmanager _instance;
		return _instance;
	}
	~Windowmanager() {}
#pragma endregion Singleton

	void Init(sf::RenderWindow* window)
	{
		_window = window;
	}
	void CreateWindow(float width = 400, float height = 280, float left = -1, float top = -1);
	void RedrawWindows();
	void MouseClick(float x, float y, sf::Mouse::Button button);

private:
	sf::RenderWindow* _window;
	std::vector<AwesomeWindow*> _windows;
	
#pragma region Singleton

	Windowmanager() { } 								/* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
														// protected, wenn man von der Klasse noch erben möchte
	Windowmanager(const Windowmanager&);				/* verhindert, dass eine weitere Instanz via
														   Kopie-Konstruktor erstellt werden kann */
	Windowmanager &operator = (const Windowmanager &);
#pragma endregion Singleton
};

