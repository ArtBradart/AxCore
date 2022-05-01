#include "AxTestMenu.h"

namespace Ax {

AxTestMenu::AxTestMenu()
{
	auto addListItem = [&](const function<void()>& func, const string& name, StdColors color) {
		AxMenuItem* item = new AxMenuItem();
		item->SetAction(func);
		item->SetText(name);
		item->SetColor((WORD)color);
		item->SetLocation({ 0, GetChildsCount() });
		AddChild(item);
	};

	addListItem([]() {}, "One", StdColors::Item);
	addListItem([]() {}, "Two", StdColors::Item);
	addListItem([]() {}, "Three", StdColors::Item);
}

}