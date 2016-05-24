#pragma once
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
	void CreateWindow();
	void xyz() {};

private:
	sf::RenderWindow* _window;
	
#pragma region Singleton

	Windowmanager() { } 	/* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
														// protected, wenn man von der Klasse noch erben möchte
	Windowmanager(const Windowmanager&);	/* verhindert, dass eine weitere Instanz via
														Kopie-Konstruktor erstellt werden kann */
	Windowmanager & operator = (const Windowmanager &);
#pragma endregion Singleton
};

