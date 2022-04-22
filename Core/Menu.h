#pragma once

#include "Title.h"
#include "MenuItem.h"
#include "MenuList.h"

class Menu
{
public:
	Menu();
	Menu(const string& text);
	Menu(const Title& title);

	Title _title;
	MenuList _list;
};
