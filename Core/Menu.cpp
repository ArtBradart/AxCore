#include "Menu.h"

Menu::Menu()
	: _title("Menu")
{}

Menu::Menu(const string & text)
	: _title(text)
{
}

Menu::Menu(const Title & title)
	: _title(title)
{
}
