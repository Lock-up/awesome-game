#pragma once

#define BorderWidth 4
#define ControlBarHeight 28
#define ControlBarMargin 4
#define ControlMargin 12

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
	void CreateWindow(float width = 400, float height = 280);

private:
	sf::RenderWindow* _window;
	
#pragma region Singleton

	Windowmanager() { } 	/* verhindert, dass ein Objekt von au�erhalb von N erzeugt wird. */
														// protected, wenn man von der Klasse noch erben m�chte
	Windowmanager(const Windowmanager&);	/* verhindert, dass eine weitere Instanz via
														Kopie-Konstruktor erstellt werden kann */
	Windowmanager & operator = (const Windowmanager &);
#pragma endregion Singleton
};

