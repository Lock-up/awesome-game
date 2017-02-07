#pragma once
#include "stdafx.h"
#include "Screens\Menu\Main.h"

namespace Screens
{
	namespace Menu
	{
		class Main
		{
		public:
			static void Screens::Menu::Main::LoadWidgets(tgui::Gui& gui)
			{
				// Get a bound version of the window size
				// Passing this to setPosition or setSize will make the widget automatically update when the view of the gui changes
				auto windowWidth = tgui::bindWidth(gui);
				auto windowHeight = tgui::bindHeight(gui);

				tgui::HorizontalLayout::Ptr hlayout = std::make_shared<tgui::HorizontalLayout>();
				hlayout->setSize(windowWidth, windowHeight);
				hlayout->setPosition(0, 0);
				gui.add(hlayout);

				tgui::VerticalLayout::Ptr vlayout = std::make_shared<tgui::VerticalLayout>();
				vlayout->setSize(200, windowHeight);
				hlayout->add(vlayout);

				hlayout->insertSpace(0, 0.75);
				hlayout->insertSpace(2, 0.75);

				// Buttons
				tgui::Button::Ptr button1 = std::make_shared<tgui::Button>();
				button1->setText("Singleplayer");
				vlayout->add(button1);
				
				tgui::Button::Ptr button2 = tgui::Button::copy(button1);
				button2->setText("Multiplayer");
				vlayout->add(button2);

				tgui::Button::Ptr button3 = tgui::Button::copy(button1);
				button3->setText("Editor");
				vlayout->add(button3);

				tgui::Button::Ptr button4 = tgui::Button::copy(button1);
				button4->setText("Options");
				vlayout->add(button4);

				tgui::Button::Ptr button5 = tgui::Button::copy(button1);
				button5->setText("Credits");
				vlayout->add(button5);

				tgui::Button::Ptr button6 = tgui::Button::copy(button1);
				button6->setText("Exit");
				vlayout->add(button6);
				
				vlayout->insertSpace(0, 2);
				vlayout->insertSpace(7, 2);
			}
		};
	};
};
