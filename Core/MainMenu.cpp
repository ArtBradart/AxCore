#include "MainMenu.h"

#include "MenuHandler.h"

MainMenu::MainMenu()
	: _Running(true)
{
	Begin();
}

MainMenu::~MainMenu()
{
}

bool MainMenu::ConstructMenu(Menu& menu)
{
	menu._title.SetColor(0x00f0);
	menu._title.SetText("Main menu");

	menu._list.Add(MenuItem([](){}, "One", StdColors::Item));
	menu._list.Add(MenuItem([](){}, "Two", StdColors::Item));
	menu._list.Add(MenuItem([](){}, "Three", StdColors::Item));

	return true;
}


void MainMenu::Begin()
{
	while (Tick());
}

bool MainMenu::Tick()
{
	Menu menu;
	if (!ConstructMenu(menu)) return false;
	MenuHandler handler(menu);

	return _Running;
}