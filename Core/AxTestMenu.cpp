#include "AxTestMenu.h"
#include <iostream>


namespace Ax {

AxTestMenu::AxTestMenu()
{
	auto addListItem = [&](const function<void()>& func, const string& name, StdColors color) {
		AxMenuItem* item = new AxMenuItem();
		item->SetAction(func);
		item->SetText(name);
		item->SetColor((WORD)color);
		Add(item);
	};

	addListItem([]() {}, "One", StdColors::Item);
	addListItem([]() {}, "Two", StdColors::Item);
	addListItem([]() {}, "Three", StdColors::Item);
}

}