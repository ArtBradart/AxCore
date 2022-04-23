#include "AxMenu.h"

namespace Ax {

AxMenu::AxMenu()
	: _title("Menu")
{}

AxMenu::AxMenu(const string& text)
	: _title(text)
{
}

AxMenu::AxMenu(const AxLabel& title)
	: _title(title)
{
}

}