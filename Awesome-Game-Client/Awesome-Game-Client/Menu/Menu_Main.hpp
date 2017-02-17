#pragma once
class Menu_Main
{
public:
	Menu_Main(tgui::Gui& gui);
	~Menu_Main();
	void LoadWidgets();

private:
	tgui::Gui& _gui;
};

